#pragma once

#include <vector>
#include <memory>

#include "Processor.h"
#include "BadArgumentException.h"
#include "EntityManager.h"

using std::shared_ptr;

class World
{
	// Singleton that makes the entity-component-processor system work.

    std::vector<shared_ptr<Processor>> processors;

public:
    static World& getInstance();
    void registerProcessor(shared_ptr<Processor> proc_ptr);
	void deregisterProcessor(shared_ptr<Processor> proc_ptr);
private:
    World();                
    World(World const&);
    void operator=(World const&);
    
};

