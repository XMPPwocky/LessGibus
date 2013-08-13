#pragma once
#include <coment\managers\manager.h>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>
#include "get_file_contents.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

static const fs::path AssetDirectoryPath = "../../assets/";
class ResourceManager
	: public coment::Manager
{
public:
	template <typename T>
	T* load(const fs::path &filename);

protected:
	template <typename T> 
	T* loadResource(const fs::path &);

	template<>
	std::string *loadResource(const fs::path & filename);
};


template <typename T>
T* ResourceManager::load(const fs::path & name)
{
	// A static map for this resource type
	typedef std::map<const fs::path, T*> ResourceMap;
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
static T* ResourceManager::loadResource(const fs::path & name)
{
	return nullptr;
}

template<>
static std::string *ResourceManager::loadResource(const fs::path & filename) 
{
	std::string *s = new std::string(get_file_contents(filename));
	return s;
}
