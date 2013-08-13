#include "stdafx.h"
#include "MeshRenderSystem.h"
#include <boost/foreach.hpp>

MeshRenderSystem::MeshRenderSystem()
{
	m_projection = glm::perspective(90.0, 1.0, 0.1, 1.0);
}

void MeshRenderSystem::registered()
{
	registerComponent<MeshComponent>();
}

void MeshRenderSystem::added(const coment::Entity &e)
{
	// Add entity to scene graph
	_scenegraph.push_back(e);
}
void MeshRenderSystem::removed(const coment::Entity &e)
{
	// Remove entity from scene graph
	auto i = std::find(_scenegraph.begin(), _scenegraph.end(), e);
	if (i != _scenegraph.end())
	{
		_scenegraph.remove(*i);
	}
}

void MeshRenderSystem::processEntities(std::vector<coment::Entity>& entities)
{
	// Render scene graph
	coment::Entity e;
	BOOST_FOREACH(e, _scenegraph)
	{
		MeshComponent *mesh_comp = _world->getComponent<MeshComponent>(e);
		std::shared_ptr<Mesh> mesh = mesh_comp->mesh;
		gl::BindVertexArray(mesh->getVAO());
		gl::DrawElements(gl::TRIANGLES, mesh->getNumtris(), gl::UNSIGNED_INT, nullptr);

	}
	//
	//

	////gl::UniformMatrix4fv(mesh->shaderprogram->getUniformLocation("MVP"), 1, 0, glm::value_ptr(MVP));
	//gl::BindVertexArray(mesh->getVAO());
	//gl::DrawElements(gl::TRIANGLES, mesh->getNumtris(), gl::UNSIGNED_INT, nullptr);
}
