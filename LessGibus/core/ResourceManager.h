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
	T* load(const std::string filename);

protected:
	template <typename T> 
	T* loadResource(const std::string filename);

	template<>
	std::string *loadResource(const std::string filename);
};


template <typename T>
T* ResourceManager::load(const std::string name)
{
	// A static map for this resource type
	typedef std::map<const std::string, T*> ResourceMap;
	static ResourceMap resources;

	T* resource = nullptr;

	// Check if resource exists
	ResourceMap::iterator lb = resources.lower_bound(name);

	if (lb != resources.end() && !(resources.key_comp()(name, lb->first)))
	{
		// The key already exists
		resource = (lb->second);
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


template <typename T>
static T* ResourceManager::loadResource(const std::string name)
{
	return nullptr;
}

template<>
static std::string *ResourceManager::loadResource(const std::string filename) 
{
	std::string *s = new std::string(get_file_contents(filename.c_str()));
	return s;
}
