#include "stdafx.h"
#include "Component.h"


Component::Component(const Entity &ent)
{
	m_ent = &ent;
	m_ent->getManager().registerComponent(*m_ent, *this);
}



Component::~Component(void)
{
	m_ent->getManager().deregisterComponent(*m_ent, *this);
}
