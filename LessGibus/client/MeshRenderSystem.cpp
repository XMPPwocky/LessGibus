#include "stdafx.h"
#include "MeshRenderSystem.h"

MeshRenderSystem::MeshRenderSystem()
{
	m_projection = glm::perspective(90.0, 1.0, 0.1, 1.0);
}

void MeshRenderSystem::registered()
{
	registerComponent<MeshComponent>();
}


void MeshRenderSystem::begin()
{

}
void MeshRenderSystem::process(const coment::Entity& entity)
{
	MeshComponent *mesh_comp = _world->getComponent<MeshComponent>(entity);
	std::shared_ptr<Mesh> mesh = mesh_comp->mesh;

	//gl::UniformMatrix4fv(mesh->shaderprogram->getUniformLocation("MVP"), 1, 0, glm::value_ptr(MVP));
	gl::BindVertexArray(mesh->_VAO);
	gl::DrawElements(gl::TRIANGLES, mesh->_numtris, gl::UNSIGNED_INT, nullptr);
}
void MeshRenderSystem::end()
{
	
}