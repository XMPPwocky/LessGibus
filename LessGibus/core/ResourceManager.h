#pragma once
#include <coment\managers\manager.h>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>
#include "get_file_contents.h"

static const std::wstring AssetDirectoryPath = L"../../asset/";
class ResourceManager
	: public coment::Manager
{
public:
	template <typename T>
	std::shared_ptr<T> load(std::string filename);

protected:
	template <typename T> 
	std::shared_ptr<T> loadResource(std::string filename);
};


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
		resource = (std::shared_ptr<T>)(lb->second);
	}
	else
	{
		if (resource = loadResource<T>(name))
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
static std::shared_ptr<T> ResourceManager::loadResource(std::string name)
{
	return nullptr;
}

template<>
static std::shared_ptr<std::string> ResourceManager::loadResource(std::string filename)
{
	return std::shared_ptr<std::string>(&get_file_contents(filename.c_str()));
}