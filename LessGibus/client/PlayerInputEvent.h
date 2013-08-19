#pragma once
#include "stdafx.h"
#include "keybindings.h"

struct PlayerInputEvent
{
	struct MouseEventInfo
	{
		glm::ivec2 delta;
		glm::ivec2 absolute;
	};

	struct KeyboardEventInfo
	{
		Keybinding key;
		std::vector<ModifierKey> modifiers;
	};

public:
	boost::optional<MouseEventInfo> mouse;

};

