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

void World::registerProcessor(const Processor& proc) {
	processors.push_back(&proc);
}
