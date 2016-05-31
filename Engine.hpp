#pragma once

#include <rapidjson/rapidjson.h>
#include <rapidxml/rapidxml.hpp>
#include <lua/lua.hpp>

#include <cstdint>
#include <cstdarg>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <deque>

#include <boost/log/sources/logger.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>

using namespace std;
using namespace boost;

#if defined(_WIN32) ||  defined(_WIN64)
#define __WINDOW__
#endif

#ifdef __WINDOW__
#define __METHOD__ __FUNCTION__
#else
#define __METHOD__ __PRETTY_FUNCTION__
#endif

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#include "log/LogEngine.hpp"
