#pragma once

#include <string>
#include <boost/exception/exception.hpp>
#include <boost/exception/error_info.hpp>


typedef boost::error_info<struct error_wstring, std::wstring> wstring_info;
