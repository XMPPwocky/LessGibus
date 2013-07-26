#pragma once
#include <stdint.h>
#include <array>

typedef uint16_t ent_id_t;
class EntityManager;

#include "EntityManager.h"



typedef EntityManager butt;

class Entity
{
	EntityManager* m_mgr;
	ent_id_t m_id;
public:
	Entity(EntityManager *mgr_ptr);
	Entity(void);
	~Entity(void);
	ent_id_t getID(void) const;
};

