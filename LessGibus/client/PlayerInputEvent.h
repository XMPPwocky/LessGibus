#pragma once
#include "stdafx.h"
#include "keybindings.h"

struct PlayerInputEvent
{
	struct MouseMotionEventInfo
	{
		// the amount the mouse has moved since the last mouse motion event
		glm::ivec2 delta;

		// the position in window coordinates of the mouse cursor
		glm::ivec2 absolute;
	};

	struct KeyboardEventInfo
	{
		// which key does this event describe
		Keybinding key;
		
		// is key pressed?
		bool pressed;

		// did the key change just now (e.g. did the last keyboard event also have this key pressed)
		// probably not useful
		bool edge;

		// which modifers are pressed
		std::map<ModifierKey, bool> modifiers;

	};

public:
	boost::optional<MouseMotionEventInfo> mousemotion;
	boost::optional<KeyboardEventInfo> keyboard;
};

