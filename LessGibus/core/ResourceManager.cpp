#include "stdafx.h"
#include "ResourceManager.h"



// Load a resource of type T from file filename
template <typename T>
std::shared_ptr<T> ResourceManager::load(std::string name)
{
	// A static map for this resource type
	typedef std::map<std::string, std::shared_ptr<T>> ResourceMap;
	static ResourceMap resources;

	std::shared_ptr<T> resource = nullptr;

	// Check if resource exists
	ResourceMap::iterator lb = resources.lower_bound(name);

	if (lb != resources.end() && !(resources.key_comp()(name, lb->first)))
	{
		// The key already exists
		resource = (std::shared_ptr<T>)((T*)lb->second);
	}
	else
	{
		LPTSTR fullpath;
		PathCombine(fullpath, AssetDirectoryPath, name);
		if (resource = loadResource<T>(fullpath))
		{
			resources.insert(lb, ResourceMap::value_type(name, resource));
		}
		else
		{
			resource = nullptr;
		}
	}

	return resource;
}

// Loaders for different types
// Default - returns nullptr
template <typename T>
std::shared_ptr<T> ResourceManager::loadResource(std::string name)
{
	return nullptr;
}
