#include "stdafx.h"
#include "RenderingSystem.h"
#include "ShaderProgramComponent.h"
#include "core_signals.h"
#include "client_signals.h"
#include <coment/World.h>
#include <coment/managers/VariableManager.h>
#include <boost/foreach.hpp>
#include <boost/signals2.hpp>
#include "camera_matrix_type.h"
#include "SignalManager.h"
#include <glimg/glimg.h>
#include <BadDataException.h>
#include <Exception.h>

#include <cmath>
#include <math.h>

using boost::signals2::signal;

RenderingSystem::RenderingSystem()
{
	gl::GenBuffers(1, &_matrices_ubo);
	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferData(gl::UNIFORM_BUFFER, sizeof(glm::mat4)*NUM_GLOBAL_MATRICES, NULL, gl::STREAM_DRAW);
	gl::BindBuffer(gl::UNIFORM_BUFFER, 0);

	gl::BindBufferRange(gl::UNIFORM_BUFFER, GLOBAL_MATRICES_BINDING, _matrices_ubo, 0, sizeof(glm::mat4) * NUM_GLOBAL_MATRICES);
	
	_imgsets["ColorTexture1"] = std::move(unique_ptr<glimg::ImageSet>(glimg::loaders::stb::LoadFromFile(
		"../../assets/collada/texture1.png")));

	gl::ActiveTexture(gl::TEXTURE0);

	_textures["ColorTexture1"] = glimg::CreateTexture(_imgsets["ColorTexture1"].get(), 0);
	
	gl::BindTexture(gl::TEXTURE_2D, _textures["ColorTexture1"]);
	gl::GenSamplers(1, &_samplers["ColorTexture1"]);
	gl::BindSampler(0, _samplers["ColorTexture1"]);
	gl::SamplerParameteri(_samplers["ColorTexture1"], gl::TEXTURE_WRAP_S, gl::CLAMP_TO_EDGE);
	gl::SamplerParameteri(_samplers["ColorTexture1"], gl::TEXTURE_WRAP_T, gl::CLAMP_TO_EDGE);
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
};
void RenderingSystem::onRegistered()
{
}

void RenderingSystem::onAdded(const coment::Entity &e)
{
	ShaderProgramComponent *prog_ptr =_world->getComponent<ShaderProgramComponent>(e);
	BOOST_ASSERT(prog_ptr != nullptr);
	ShaderProgramComponent &prog = *prog_ptr;
	gl::UseProgram(prog.prog->getProgID());

	if (prog.prog->getUniformBlockIndex("GlobalMatrices") != -1)
		gl::UniformBlockBinding(prog.prog->getProgID(), prog.prog->getUniformBlockIndex("GlobalMatrices"), GLOBAL_MATRICES_BINDING);
	if (prog.prog->getUniformLocation("ColorTexture1") != -1)
		gl::Uniform1i(prog.prog->getUniformLocation("ColorTexture1"), 0);

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

	shared_ptr<const boost::signals2::signal<get_camera_matrices_signature>> camera_getter =
		_world->getManager<SignalManager>()->signal<get_camera_matrices_signature>("get_camera_matrices");
	boost::optional<std::map<camera_matrix_type, glm::mat4>> &camera_matrices_optional = (*camera_getter)();
	BOOST_ASSERT(camera_matrices_optional.is_initialized());
	std::map<camera_matrix_type, glm::mat4> camera_matrices = (camera_matrices_optional.get());

	glm::mat4 world_to_clip_matrix =  (camera_matrices[CAMERA_MATRIX_CAMERATOCLIP] * camera_matrices[CAMERA_MATRIX_WORLDTOCAMERA]);

	gl::BindBuffer(gl::UNIFORM_BUFFER, _matrices_ubo);
	gl::BufferSubData(gl::UNIFORM_BUFFER, 0, sizeof(glm::mat4), glm::value_ptr(camera_matrices[CAMERA_MATRIX_WORLDTOCAMERA]));
	gl::BufferSubData(gl::UNIFORM_BUFFER, sizeof(glm::mat4), sizeof(glm::mat4), glm::value_ptr(camera_matrices[CAMERA_MATRIX_CAMERATOCLIP]));
	gl::BufferSubData(gl::UNIFORM_BUFFER, sizeof(glm::mat4)*2, sizeof(glm::mat4), glm::value_ptr(world_to_clip_matrix));

	static glm::mat4 hack_matrix;
	hack_matrix = glm::rotate(hack_matrix, 2.5f, glm::vec3(0, 1, 0));

	// Render scene graph
	coment::Entity e;
	
	BOOST_FOREACH(e, _scenegraph)
	{
		glm::mat4 model_to_world_matrix;
		 
		ShaderProgramComponent *prog_comp_ptr = (_world->getComponent<ShaderProgramComponent>(e));
		BOOST_ASSERT(prog_comp_ptr != nullptr);
		ShaderProgramComponent &prog_comp = *prog_comp_ptr;

		gl::UniformMatrix4fv(prog_comp.prog->getUniformLocation("modelToClipMatrix"), 1, gl::FALSE_, glm::value_ptr(world_to_clip_matrix * hack_matrix * model_to_world_matrix));
		MeshComponent *mesh_comp_ptr = _world->getComponent<MeshComponent>(e);
		BOOST_ASSERT(mesh_comp_ptr != nullptr);
		MeshComponent &mesh_comp = *mesh_comp_ptr;
		std::shared_ptr<Mesh> mesh = mesh_comp.mesh;
		gl::UseProgram(prog_comp.prog->getProgID());
		gl::BindVertexArray(mesh->getVAO());
		gl::ActiveTexture(gl::TEXTURE0);
		gl::BindTexture(gl::TEXTURE_2D, _textures.at("ColorTexture1"));
		gl::DrawElements(gl::TRIANGLES, mesh->getNumtris(), gl::UNSIGNED_INT, nullptr);

	}
}
