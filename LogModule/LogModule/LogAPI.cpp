#include "LogAPI.h"

namespace
{
    bool s_isTerminated = false;
    std::mutex locker;
}

void LogModule::write_log(const std::string& cref_logFileName, const std::string& cref_classInvoker, const std::string& cref_methodInvoker, const std::string& cref_message)
{
    if (is_debug)
    {
        std::lock_guard<std::mutex> lock(locker);

        if (!s_isTerminated)
        {
            LogModule::get_instance()->write_log(cref_logFileName.c_str()
                      , cref_classInvoker.c_str()
                      , cref_methodInvoker.c_str()
                      , cref_message.c_str()
                      );
        }
    }
}

void LogModule::set_debug(bool isDebug)
{
    is_debug = isDebug;
}

void LogModule::dispose_logger()
{
    std::lock_guard<std::mutex> lock(locker);

    s_isTerminated = true;
    LogModule::get_instance()->dispose();
}


