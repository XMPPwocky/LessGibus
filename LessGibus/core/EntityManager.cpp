#include "stdafx.h"
#include "EntityManager.h"


EntityManager::EntityManager(void)
{
	entity_registry_t::iterator i;
	for (i = entity_registry.begin();
		i != entity_registry.end();
		i++)
	{
		(*i) = NULL;
	}
}

EntityManager::~EntityManager(void)
{
}

void EntityManager::registerEntity(Entity &ent)
{
	ent_id_t i;
	for (i = 0;
		i != entity_registry.size();
		i++)
	{
		if (!entity_registry[i]) // is null
		{
			entity_registry[i] = std::unique_ptr<component_ptr_list_t>(
				new component_ptr_list_t);
			break;
		}
	}
	if (i == entity_registry.size())
	{
		throw Exception(L"Out of entity IDs!");
	}
	ent.m_id = i;
}

void EntityManager::deregisterEntity(Entity &ent)
{
	entity_registry[ent.m_id] = NULL;
}

void EntityManager::registerComponent(const ent_id_t ent_id, Component &comp)
{
	component_ptr_list_t components = *entity_registry[ent_id];
	component_ptr_list_t::iterator i;
	for (i = components.begin();
		i != components.end();
		i++)
	{
		if (*i == &comp) {
			throw BadArgumentException(L"Tried to register a previously registered component!");
		}
	}

	components.push_back(&comp);
}

void EntityManager::deregisterComponent(const ent_id_t ent_id, Component &comp)
{
	component_ptr_list_t components = *entity_registry[ent_id];

	component_ptr_list_t::iterator i;
	for (i = components.begin();
		i != components.end();
		i++)
	{
		if (*i = &comp) {
			components.erase(i);
			break;
		}
	}
}

EntityManager::component_ptr_list_t EntityManager::getAllComponents(const ent_id_t ent_id)
{
	return *entity_registry[ent_id];
}

//std::pair<EntityManager::component_ptr_list_t, EntityManager::get