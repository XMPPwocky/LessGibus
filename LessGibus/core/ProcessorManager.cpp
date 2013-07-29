#include "stdafx.h"
#include "ProcessorManager.h"


ProcessorManager::ProcessorManager(void)
{


}


ProcessorManager::~ProcessorManager(void)
{
}

void ProcessorManager::registerProcessor(Processor &proc)
{
	processors.push_back(&proc);
}

void ProcessorManager::deregisterProcessor(Processor &proc)
{
	processors_t::iterator i;
	for (i = processors.begin();
		i != processors.end();
		i++)
	{
		if ((*i) = &proc)
		{
			processors.erase(i);
			break; // not sure if the iterator still works after changing the list
		}
	}
}

void ProcessorManager::processAll(action_t process)
{
	processors_t::iterator i;
	for (i = processors.begin();
		i != processors.end();
		i++)
	{
		(*i)->process(process);
	}
}

