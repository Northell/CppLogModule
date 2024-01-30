#pragma once
#include "include/LogModule.h"

namespace LogModule
{
#ifdef _WIN32
	extern  __declspec(dllexport) void write_log(const wchar_t* pathToFile, const wchar_t* classInvoker, const wchar_t* methodInvoker, const wchar_t* message);
	extern  __declspec(dllexport) void write_log(const std::string& logFileName, const std::string& classInvoker, const std::string& methodInvoker, const std::string& message);
	extern  __declspec(dllexport) void set_debug(bool isDebug);
#endif // _WIN32

}

