#ifndef COMENT_MANAGERMANAGER_H
#define COMENT_MANAGERMANAGER_H

#include <string>
#include <typeinfo>

#include "Manager.h"
#include "../utils/Map.h"

namespace coment
{
	typedef std::tr1::unordered_map<std::string, Manager*> ManagerMap;

	class ManagerManager : public Manager
	{
	public:
		ManagerManager();

		// Get a manager.
		template <typename T>
		T* getManager();

		// Add a manager
		template <typename T>
		T* registerManager(T& manager);

	private:
		// A hash map of managers by type
		ManagerMap _managers;
	};

	// Template functions
	template <typename T>
	T* ManagerManager::getManager()
	{
		return (T*)_managers[typeid(T).name()];
	}

	template <typename T>
	T* ManagerManager::registerManager(T& manager)
	{
		// Initialise manager
		((Manager*)&manager)->initialise(_world);

		// Store a pointer to this manager
		_managers[typeid(T).name()] = &manager;

		// Return a pointer
		return &manager;
	}
}

#endif /* COMENT_MANAGERMANAGER_H */
