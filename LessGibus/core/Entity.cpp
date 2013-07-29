#include "stdafx.h"
#include "Entity.h"


Entity::Entity(EntityManager& mgr)
{
	m_mgr = &mgr;
	m_mgr->registerEntity(*this);
}

Entity::Entity(const Entity &original)
{
	m_mgr = original.m_mgr;

	m_mgr->registerEntity(*this);

	// copy components
	EntityManager::component_ptr_list_t original_components = 
		m_mgr->getAllComponents(original);

	EntityManager::component_ptr_list_t::iterator i;
	for (i = original_components.begin();
		i != original_components.end();
		i++)
	{
		// FIXME: Do things here
	}
}

Entity &Entity::operator=(const Entity &original)
{
	Entity tmp(original);
	std::swap(m_mgr, tmp.m_mgr);
	std::swap(m_id, tmp.m_id);
	return *this;

}

Entity::operator const ent_id_t() const
{
	return m_id;
}

Entity::~Entity(void)
{
	m_mgr->deregisterEntity(*this);
}

EntityManager &Entity::getManager(void) const
{
	return *m_mgr;
}