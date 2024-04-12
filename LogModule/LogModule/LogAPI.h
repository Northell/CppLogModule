#pragma once
#include <iostream>
#include <mutex>
#include <memory.h>
#include <locale.h>
#include <unordered_map>
#include "include/LogModule.h"
#include "LogAPI_global.h"

namespace LogModule
{
namespace
{
    bool is_debug = false;
}

/**
 * @brief write_log method writes logs in log file
 * @param logFileName
 * @param classInvoker  name of class, where did invoked this method
 * @param methodInvoker name of method, where did invoked this method
 * @param message to write
 */
extern CPPLOGMODULE_EXPORT void write_log(const std::string& logFileName, const std::string& classInvoker, const std::string& methodInvoker, const std::string& message);

/**
 * @brief set_debug method on or off logModule
 * @param isDebug true - ON, false = OFF
 */
extern CPPLOGMODULE_EXPORT void set_debug(bool isDebug);

/**
 * @brief dispose_logger free LogModule recources
 */
extern CPPLOGMODULE_EXPORT void dispose_logger();
}

