#include "stdafx.h"
#include "EntityManager.h"


EntityManager::EntityManager(void)
{
	ent_id_t i;
	for (i = 0;
		i != entities.size();
		i++)
	{
		entities[i] = false;
	}
}


EntityManager::~EntityManager(void)
{
}

ent_id_t EntityManager::registerEntity(void)
{
	ent_id_t i;
	for (i = 0;
		i != entities.size();
		i++)
	{
		if (entities[i])
		{
			continue;
		}
	}

	return i;
}

void EntityManager::deregisterEntity(ent_id_t ent)
{
	entities[ent] = NULL;
}