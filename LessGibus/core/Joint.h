#pragma once
#include <glm.hpp>
#include <gl/GL.h>
#include <gtc/quaternion.hpp>

#include <boost/archive/text_oarchive.hpp>

#include <boost/archive/text_iarchive.hpp>

struct Joint
{
private:
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(position)
			& BOOST_SERIALIZATION_NVP(orientation)
			& BOOST_SERIALIZATION_NVP(parent);
	}

public:
	glm::vec3 position;
	glm::quat orientation;
	typedef GLuint id;
	id parent;
};