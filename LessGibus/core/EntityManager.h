#pragma once
#include "Entity.h"
#include "Exception.h"

#include <array>
#include <memory>
#include <bitset>

const ent_id_t MAX_ENTS = 8192;

class EntityManager
{
	typedef std::bitset<MAX_ENTS> entity_list_t;
	
	entity_list_t entities;
public:
	EntityManager(void);
	~EntityManager(void);
	ent_id_t registerEntity(void);
	void deregisterEntity(ent_id_t ent);
};