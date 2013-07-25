#include "stdafx.h"
#include "World.h"

World::World()
{
}

World& World::getInstance()
{
    static World instance;
    return instance;
}

void World::registerProcessor(Processor *proc_ptr) {
	std::vector<Processor *>::const_iterator i;
	for (
		i = processors.begin();
		i != processors.end();
		i++
	) {
		if (*i == proc_ptr) {
			// can't register the same processor multiple times
			throw BadArgumentException("Tried to register processor, but it was already registered!");
		}
		
	}
	// okay, it wasn't in there, add it
	processors.push_back(proc_ptr);
}
void World::deregisterProcessor(Processor *proc_ptr) {
		std::vector<Processor *>::const_iterator i;
	for (
		i = processors.begin();
		i != processors.end();
		i++
	) {
		if (*i == proc_ptr) {
			processors.erase(i);
		}
		
	}
}
