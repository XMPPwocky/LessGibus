#pragma once
#include <cstdint>
#include <queue>
#include <list>

class Processor;
enum action_t;

class ProcessorManager
{
	typedef std::list<Processor *> processors_t;
	processors_t processors;

public:
	ProcessorManager(void);
	~ProcessorManager(void);

	void registerProcessor(Processor &proc);
	void deregisterProcessor(Processor &proc);

	void processAll(action_t what);
};

#include "Processor.h"