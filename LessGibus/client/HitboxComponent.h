#pragma once
#include "Component.h"
class HitboxComponent :
	public Component
{
public:
	HitboxComponent(const Entity &ent);
	~HitboxComponent(void);
};

