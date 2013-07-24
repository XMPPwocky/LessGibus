#pragma once

#include <vector>
#include "core.h"
#include "Processor.h"

template class EXPORT std::vector<Processor>;

class CORE_API World
{
	// Singleton that makes the entity-component-processor system work.

    static World& getInstance();
	void World::registerProcessor(const Processor& proc);
private:
    World();                
    World(World const&);
    void operator=(World const&);
	std::vector<Processor> processors;
};

