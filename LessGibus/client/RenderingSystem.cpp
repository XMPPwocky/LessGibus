#include "stdafx.h"
#include "RenderingSystem.h"
#include "ShaderProgramComponent.h"
#include <coment/World.h>
#include <coment/managers/VariableManager.h>
#include <boost/foreach.hpp>
#include "Camera.h"

RenderingSystem::RenderingSystem()
{
	_projection = glm::perspective(90.0, 1.0, 0.1, 1.0);
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


	gl::GenBuffers(1, &_matrices_ubo);
	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferData(gl::UNIFORM_BUFFER, sizeof(glm::mat4), NULL, gl::STREAM_DRAW);
	gl::BindBuffer(gl::UNIFORM_BUFFER, 0);

	gl::BindBufferRange(gl::UNIFORM_BUFFER, GLOBAL_MATRICES_BINDING, _matrices_ubo, 0, sizeof(glm::mat4) * 1);

}

void RenderingSystem::onAdded(const coment::Entity &e)
{
	ShaderProgramComponent *prog =_world->getComponent<ShaderProgramComponent>(e);
	gl::UseProgram(prog->prog->getProgID());
	gl::UniformBlockBinding(prog->prog->getProgID(), prog->prog->getUniformBlockIndex("GlobalMatrices"), GLOBAL_MATRICES_BINDING);
	gl::UniformMatrix4fv(prog->prog->getUniformLocation("modelToCameraMatrix"), 1, gl::FALSE_, glm::value_ptr(glm::mat4()));
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
	// TODO: Render map
	
	// Generate transforms
	Camera cam = _world->getManager<coment::VariableManager>()->getValue<Camera>("active_camera");
	
	// TODO: handle positioning

	glm::mat4 modelToWorldMatrix;
	glm::mat4 worldToCameraMatrix = cam.getMatrix();
	glm::mat4 modelToCameraMatrix =  (worldToCameraMatrix * modelToWorldMatrix);

	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferSubData(gl::UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(_projection));



	// Render scene graph
	coment::Entity e;
	BOOST_FOREACH(e, _scenegraph)
	{
		ShaderProgramComponent *prog_comp = _world->getComponent<ShaderProgramComponent>(e);
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