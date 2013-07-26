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
		if (!entities[i])
		{
			entities[i] = true;
			break;
		}
	}
	if (i == entities.size())
	{
		throw Exception(L"Out of entity IDs!");
	}
	return i;
}

void EntityManager::deregisterEntity(ent_id_t ent)
{
	entities[ent] = NULL;
}