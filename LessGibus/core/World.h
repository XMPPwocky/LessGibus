#pragma once

#include <vector>

#include "Processor.h"
#include "BadArgumentException.h"


class World
{
	// Singleton that makes the entity-component-processor system work.
    std::vector<Processor *> processors;
    
public:
    static World& getInstance();
    void registerProcessor(Processor *proc_ptr);
	void deregisterProcessor(Processor *proc_ptr);
private:
    World();                
    World(World const&);
    void operator=(World const&);
    
};

