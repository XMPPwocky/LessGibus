#pragma once
#include <stdint.h>
#include <array>

typedef uint16_t ent_id_t;
class EntityManager;


class Entity
{
	EntityManager* m_mgr;

public:
	Entity(EntityManager &mgr);
	Entity(const Entity &original);
	Entity &operator=(const Entity &original);
	operator const ent_id_t() const;
	virtual ~Entity(void);

	EntityManager &getManager(void) const;
	ent_id_t m_id;
};

#include "EntityManager.h"