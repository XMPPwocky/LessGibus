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

void World::registerProcessor(shared_ptr<Processor> proc_ptr) {
	processors.insert(proc_ptr);
}
void World::deregisterProcessor(shared_ptr<Processor> proc_ptr) {
	processors.erase(proc_ptr);
}
