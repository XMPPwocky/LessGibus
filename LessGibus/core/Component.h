#pragma once
#include <cstdint>
#include "Entity.h"
#include "EntityManager.h"

class Component
{
	const Entity *m_ent;

public:
	Component(const Entity &ent);
	virtual ~Component(void);
};
