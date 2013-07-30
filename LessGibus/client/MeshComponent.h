#pragma once
#include <coment/Component.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <vector>
#include <array>
#include <tuple>

struct MeshComponent :
	public coment::Component
{
	static const int MAX_JOINTS_PER_VERTEX = 4;
	// inspired by Doom 3's MD5Mesh format
	struct Material
	{
		glm::uint_t shader_program;
		glm::uint_t texture;
	};
	struct Joint
	{ // These joints will be deformed by the AnimationSystem
		Joint *parent;
		glm::vec3 position;
		glm::quat orientation;
	};
	struct Vertex
	{
		glm::vec2 uv;

		typedef std::array<glm::float_t, MAX_JOINTS_PER_VERTEX> weights_t; // all members of this must sum to 1
		typedef std::array<Joint *, MAX_JOINTS_PER_VERTEX> joint_ptrs_t; 
		typedef std::array<glm::vec3, MAX_JOINTS_PER_VERTEX> vert_offsets_t; // position of this vertex in joint space

		typedef std::tuple<weights_t, joint_ptrs_t, vert_offsets_t> vertex_joints_t;

		vertex_joints_t joints;
	};
	struct Triangle
	{
		(Vertex *) v1, v2, v3;
	};

	Material mat;
	std::vector<Joint> joints;
	std::vector<Vertex> vertex;
	std::vector<Triangle> triangles;
};