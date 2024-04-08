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
        if (!s_isTerminated)
        {
            LogModule* pInstance = LogModule::get_instance();

            if (pInstance != nullptr)
            {
                std::lock_guard<std::mutex> lock(locker);

                if (!s_isTerminated)
                {
                    if (cref_logFileName.size()>0)
                    {
                        pInstance->write_log(cref_logFileName.c_str()
                                             , cref_classInvoker.c_str()
                                             , cref_methodInvoker.c_str()
                                             , cref_message.c_str()
                                             );
                    }
                }
            }
        }
    }
}

void LogModule::set_debug(bool isDebug)
{
    is_debug = isDebug;
}

void LogModule::dispose_logger()
{
    s_isTerminated = true;

    LogModule* pInstance = LogModule::get_instance();

    if (pInstance != nullptr)
    {
        pInstance->dispose();
    }
}


