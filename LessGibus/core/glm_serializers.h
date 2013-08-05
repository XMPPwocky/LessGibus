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
	ar & BOOST_SERIALIZATION_NVP(quaternion.w)
		& BOOST_SERIALIZATION_NVP(quaternion.x)
		& BOOST_SERIALIZATION_NVP(quaternion.y)
		& BOOST_SERIALIZATION_NVP(quaternion.z);
}


template<class Archive, class valuetype>
void serialize(Archive & ar, glm::detail::tvec3<valuetype> quaternion, const unsigned int version)
{
	ar & BOOST_SERIALIZATION_NVP(quaternion.x)
		& BOOST_SERIALIZATION_NVP(quaternion.y)
		& BOOST_SERIALIZATION_NVP(quaternion.z);
}

} // namespace serialization
} // namespace boost