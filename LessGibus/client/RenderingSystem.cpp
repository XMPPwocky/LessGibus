#include "stdafx.h"
#include "RenderingSystem.h"
#include "ShaderProgramComponent.h"
#include "core_signals.h"
#include "client_signals.h"
#include <coment/World.h>
#include <coment/managers/VariableManager.h>
#include <boost/foreach.hpp>
#include <boost/signals2.hpp>
#include "Camera.h"

#include <cmath>
#include <math.h>

using std::shared_ptr;
using std::unique_ptr;
using boost::signals2::signal;

RenderingSystem::RenderingSystem()
{
	gl::GenBuffers(1, &_matrices_ubo);
	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferData(gl::UNIFORM_BUFFER, sizeof(glm::mat4), NULL, gl::STREAM_DRAW);
	gl::BindBuffer(gl::UNIFORM_BUFFER, 0);

	gl::BindBufferRange(gl::UNIFORM_BUFFER, GLOBAL_MATRICES_BINDING, _matrices_ubo, 0, sizeof(glm::mat4) * NUM_GLOBAL_MATRICES);
	
	//_projection = glm::perspective(90.0f, 1.0f, 0.01f, 1.0f);
	//_projection = glm::mat4();
}

RenderingSystem::~RenderingSystem()
{
	gl::DeleteBuffers(1, &_matrices_ubo);
}
void RenderingSystem::registerComponents()
{
	registerComponent<ShaderProgramComponent>();
	registerComponent<MeshComponent>();
}
void RenderingSystem::onRegistered()
{
}

void RenderingSystem::onAdded(const coment::Entity &e)
{
	ShaderProgramComponent *prog =_world->getComponent<ShaderProgramComponent>(e);
	gl::UseProgram(prog->prog->getProgID());
	gl::UniformBlockBinding(prog->prog->getProgID(), prog->prog->getUniformBlockIndex("GlobalMatrices"), GLOBAL_MATRICES_BINDING);
	
	// Add entity to scene graph
	_scenegraph.push_back(e);
}
void RenderingSystem::onRemoved(const coment::Entity &e)
{
	// Remove entity from scene graph
	auto i = std::find(_scenegraph.begin(), _scenegraph.end(), e);
	if (i != _scenegraph.end())
	{
		_scenegraph.remove(*i);
	}
}

void RenderingSystem::processEntities(std::vector<coment::Entity>& entities)
{
	gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

	// TODO: Render map

	const unique_ptr<camera_matrices_get_signal> &camera_getter =
		_world->getManager<coment::VariableManager>()->getValue<unique_ptr<camera_matrices_get_signal>>("get_camera_matrices");
	boost::optional<std::map<camera_matrix_type, glm::mat4>> &camera_matrices_optional = (*camera_getter)();
	BOOST_ASSERT(camera_matrices_optional.is_initialized());
	std::map<camera_matrix_type, glm::mat4> camera_matrices = (camera_matrices_optional.get());

	glm::mat4 world_to_clip_matrix =  (camera_matrices[CAMERA_MATRIX_CAMERATOCLIP] * camera_matrices[CAMERA_MATRIX_WORLDTOCAMERA]);

	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferSubData(gl::UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(camera_matrices[CAMERA_MATRIX_WORLDTOCAMERA]));
	gl::BufferSubData(gl::UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4)*2, glm::value_ptr(camera_matrices[CAMERA_MATRIX_CAMERATOCLIP]));
	gl::BufferSubData(gl::UNIFORM_BUFFER, sizeof(glm::mat4)*2, sizeof(glm::mat4)*3, glm::value_ptr(world_to_clip_matrix));

	static float rotation;
	rotation = fmodf(rotation + (10*_world->getDelta()), 360);

	// Render scene graph
	coment::Entity e;
	
	BOOST_FOREACH(e, _scenegraph)
	{
		glm::mat4 model_to_world_matrix; // TODO: Actually put something in here
		 
		ShaderProgramComponent *prog_comp = _world->getComponent<ShaderProgramComponent>(e);
		gl::UniformMatrix4fv(prog_comp->prog->getUniformLocation("modelToClipMatrix"), 1, gl::FALSE_, glm::value_ptr(world_to_clip_matrix * model_to_world_matrix));
		MeshComponent *mesh_comp = _world->getComponent<MeshComponent>(e);
		std::shared_ptr<Mesh> mesh = mesh_comp->mesh;
		gl::UseProgram(prog_comp->prog->getProgID());
		gl::BindVertexArray(mesh->getVAO());
		gl::DrawElements(gl::TRIANGLES, mesh->getNumtris(), gl::UNSIGNED_INT, nullptr);

	}
	//
	//

	////gl::UniformMatrix4fv(mesh->shaderprogram->getUniformLocation("MVP"), 1, 0, glm::value_ptr(MVP));
	//gl::BindVertexArray(mesh->getVAO());
	//gl::DrawElements(gl::TRIANGLES, mesh->getNumtris(), gl::UNSIGNED_INT, nullptr);
}
