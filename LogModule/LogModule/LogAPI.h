#pragma once
#include <iostream>
#include <mutex>
#include <memory.h>
#include <locale.h>

#include "include/LogModule.h"
#include "LogAPI_global.h"

namespace LogModule
{
namespace
{
    bool is_debug = false;
}

extern CPPLOGMODULE_EXPORT void write_log(const std::string& logFileName, const std::string& classInvoker, const std::string& methodInvoker, const std::string& message);
extern CPPLOGMODULE_EXPORT void set_debug(bool isDebug);
extern CPPLOGMODULE_EXPORT void dispose_logger();
}

