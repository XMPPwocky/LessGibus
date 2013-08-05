#pragma once
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>


namespace boost {
namespace serialization {

template<class Archive, class valuetype>
void serialize(Archive & ar, glm::detail::tquat<valuetype> quaternion, const unsigned int version)
{
	ar & quaternion.w;
	ar & quaternion.x;
	ar & quaternion.y;
	ar & quaternion.z;
}


template<class Archive, class valuetype>
void serialize(Archive & ar, glm::detail::tvec3<valuetype> quaternion, const unsigned int version)
{
	ar & quaternion.x;
	ar & quaternion.y;
	ar & quaternion.z;
}

} // namespace serialization
} // namespace boost