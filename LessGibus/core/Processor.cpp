#include "stdafx.h"
#include "Processor.h"


Processor::Processor(ProcessorManager &mgr)
{
	m_mgr = &mgr;
	m_mgr->registerProcessor(*this);
}


Processor::~Processor(void)
{
	m_mgr->deregisterProcessor(*this);
}
