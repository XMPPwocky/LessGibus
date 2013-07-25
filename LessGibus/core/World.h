#pragma once

#include <set>
#include <memory>

#include "Processor.h"

using std::unique_ptr;
class World
{
	// Singleton that makes the entity-component-processor system work.
    std::set<Processor *> processors;
    
public:
    static World& getInstance();
    void registerProcessor(Processor *proc_ptr);
private:
    World();                
    World(World const&);
    void operator=(World const&);
    
};

