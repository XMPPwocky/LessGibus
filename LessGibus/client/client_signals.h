#pragma once

#include "stdafx.h"
#include <string>
#include <memory>
#include "CameraComponent.h"
#include "camera_matrix_type.h"
#include "PlayerInputEvent.h"
#include <glm/glm.hpp>

typedef std::map<camera_matrix_type, glm::mat4> get_camera_matrices_signature();
typedef void sdl_event_signature(const SDL_Event &e);
typedef void player_input_event_signature(const PlayerInputEvent &e);