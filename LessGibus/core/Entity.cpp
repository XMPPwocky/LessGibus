#include "stdafx.h"
#include "Entity.h"


Entity::Entity(EntityManager& mgr_ptr)
{
	m_mgr = &mgr_ptr;
	m_id = m_mgr->registerEntity();
}


Entity::~Entity(void)
{
	m_mgr->deregisterEntity(m_id);
}

ent_id_t Entity::getID(void) const
{
	return m_id;
}
