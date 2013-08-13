#pragma once
#include <coment\managers\manager.h>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>
#include "get_file_contents.h"
#include <boost/filesystem.hpp>
#include <typeinfo>
#include <map>
#include <boost/any.hpp>

namespace fs = boost::filesystem;

static const fs::path AssetDirectoryPath = "../../assets/";
class ResourceManager
	: public coment::Manager
{
public:
	template <typename T>
	std::shared_ptr<T> load(const fs::path &filename);

protected:
	template <typename T> 
	T* loadResource(const fs::path &);

	template<>
	std::string *loadResource(const fs::path & filename);


	typedef std::map<fs::path, boost::any> Cache;


	template <typename T>
	Cache *getCache();

	typedef std::map<const char *, Cache> CacheMap; // first template = type_info::name
	

	CacheMap caches;
};

template <typename T>
ResourceManager::Cache *ResourceManager::getCache()
{	
	return &caches[typeid(T).name()];
}

template <typename T>
std::shared_ptr<T> ResourceManager::load(const fs::path & name)
{
	Cache *cache = getCache<T>();

	std::shared_ptr<T> resource = nullptr;

	// Check if resource exists
	Cache::iterator lb = cache->lower_bound(name);

	if (lb != cache->end() && !(cache->key_comp()(name, lb->first)))
	{
		// The key already exists
		resource = boost::any_cast<std::shared_ptr<T>>(lb->second);
	}
	else
	{
		if (T* raw_ptr = (loadResource<T>(name)))
		{
			resource = std::shared_ptr<T>(raw_ptr);
			cache->insert(lb, Cache::value_type(name,
				(resource)));
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
