#pragma once

#include <vector>

#include "Processor.h"

class  World
{
	// Singleton that makes the entity-component-processor system work.
    std::vector<Processor *> processors;
    
public:
    static World& getInstance();
    void World::registerProcessor(const Processor& proc);
private:
    World();                
    World(World const&);
    void operator=(World const&);
    
};

