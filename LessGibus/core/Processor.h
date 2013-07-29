#pragma once


#include <cstdint>

class ProcessorManager;
enum action_t
{
	ACTION_UPDATE,
	ACTION_DRAW
};

class  Processor
{
	ProcessorManager *m_mgr;
public:
	Processor(ProcessorManager &mgr);
	virtual ~Processor(void);

	virtual void process(action_t what)=0;
	
};

#include "ProcessorManager.h"
