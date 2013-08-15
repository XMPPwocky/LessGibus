#pragma once

#include <boost/signals2.hpp>
#include <string>
#include <memory>
#include "Camera.h"
#include <glm/glm.hpp>

typedef boost::signals2::signal<std::map<camera_matrix_type, glm::mat4> ()> camera_matrices_get_signal;