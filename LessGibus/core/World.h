#pragma once

#include <set>
#include <memory>

#include "Processor.h"

using std::shared_ptr;
class World
{
	// Singleton that makes the entity-component-processor system work.
    std::set<shared_ptr<Processor>> processors;
    
public:
    static World& getInstance();
    void registerProcessor(shared_ptr<Processor> proc_ptr);
	void deregisterProcessor(shared_ptr<Processor> proc_ptr);
private:
    World();                
    World(World const&);
    void operator=(World const&);
    
};

