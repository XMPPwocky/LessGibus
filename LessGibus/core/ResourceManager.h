#pragma once
#include <coment\managers\manager.h>
#include <string>
#include <Windows.h>
#include <Shlwapi.h>
#include <memory>

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
