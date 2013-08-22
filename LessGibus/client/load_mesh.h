#include "Mesh.pb.h"
#include "Mesh.h"

Mesh *load_mesh(const protobuf::Mesh &data, const std::map<const std::string, GLuint> &attrib_locations);