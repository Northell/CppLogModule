#include "LogAPI.h"

namespace
{
std::atomic<bool> s_isTerminated = false;
LogModule::LogModule s_logModule;
}

void LogModule::write_log(const std::string& cref_logFileName, const std::string& cref_classInvoker, const std::string& cref_methodInvoker, const std::string& cref_message)
{
    LogModule* pInstance = nullptr;

    try
    {
        if (is_debug)
        {
            if (!s_isTerminated)
            {
                if ((cref_logFileName.size()>0)
                        && (cref_classInvoker.size()>0)
                        && (cref_methodInvoker.size()>0))
                {
                    s_logModule.write_log(cref_logFileName, cref_classInvoker, cref_methodInvoker, cref_message);
                }
            }
        }

    }
    catch(const std::exception& ex)
    {
        //NOTHING
    }
}

void LogModule::set_debug(bool isDebug)
{
    is_debug = isDebug;
}

void LogModule::dispose_logger()
{
    s_isTerminated = true;
    s_logModule.dispose();
}


