#pragma once

#include <fstream>
#include <string>
#include <cerrno>

#include "ResourceManager.h"
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

static std::string get_file_contents(const fs::path &filename)
{
  std::ifstream in(filename.string(), std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize((unsigned int)in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();

    return(contents);
  }

  throw(errno);
}
