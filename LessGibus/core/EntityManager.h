#pragma once
#include "Entity.h"
#include "Exception.h"
#include "Component.h"
#include "BadArgumentException.h"

#include <array>
#include <memory>
#include <bitset>
#include <map>
#include <list>

const ent_id_t MAX_ENTS = 8192;
class Entity;
class Component;

class EntityManager
{
public:
	typedef std::list<const Component *> component_ptr_list_t;
	typedef std::array<std::unique_ptr<component_ptr_list_t>, MAX_ENTS> entity_registry_t;

private:
	entity_registry_t entity_registry;

	void registerEntity(Entity &ent);
	void deregisterEntity(Entity &ent);

	
	void registerComponent(const ent_id_t ent_id, Component &comp);
	void deregisterComponent(const ent_id_t ent_id, Component &comp);

public:

	EntityManager(void);
	~EntityManager(void);

	friend class Entity;
	friend class Component;

	component_ptr_list_t getAllComponents(const ent_id_t ent_id);
};