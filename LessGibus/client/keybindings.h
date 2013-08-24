#pragma once

#include "stdafx.h"

enum Keybinding
{
	KEYBIND_MOVEFORWARD, // default W
	KEYBIND_MOVEDOWN, // default S
	KEYBIND_MOVELEFT, // default A
	KEYBIND_MOVERIGHT, // default D
	KEYBIND_JUMP, // default SPACE
	KEYBIND_PRIMARYFIRE, // default MOUSE1
	KEYBIND_ALTERNATEFIRE, // default MOUSE2
	KEYBIND_CROUCH, // default left shift
};

enum ModifierKey
{
	MODIFIER_1, // default ctrl
	MODIFIER_2, // default alt
	MODIFIER_3  // default shift
};

static const std::map<char, Keybinding> default_keybinds = boost::assign::map_list_of
	('w', KEYBIND_MOVEFORWARD);