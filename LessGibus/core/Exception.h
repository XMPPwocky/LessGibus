#pragma once

#include <string>
#include <boost/exception/all.hpp>
#include <boost/exception/error_info.hpp>


typedef boost::error_info<struct tag_wstring, std::wstring> wstring_info;
