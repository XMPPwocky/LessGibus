#ifndef COMENT_ENTITYPROCESSINGSYSTEM_H
#define COMENT_ENTITYPROCESSINGSYSTEM_H

#include <vector>

#include "../Entity.h"
#include "../systems/EntitySystem.h"

namespace coment
{
	class EntityProcessingSystem
		: public EntitySystem
	{
	public:
		EntityProcessingSystem();

		// Process a single entity, override to specify behaviour
		virtual void process(const Entity& e) = 0;

		// Whether to currently process this entity
		virtual bool checkProcessing();

		// Automatically call process for each entity
		void processEntities(std::vector<Entity>& entities);
	};
};

#endif /* COMENT_ENTITYPROCESSINGSYSTEM_H */
