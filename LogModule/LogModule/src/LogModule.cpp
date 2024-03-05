#include "../include/LogModule.h"

LogModule::LogModule* LogModule::LogModule::s_pInstance = nullptr;

void LogModule::LogModule::init()
{
    m_terminated = false;
}

LogModule::LogModule *LogModule::LogModule::get_instance()
{
    if (s_pInstance==nullptr)
    {
        s_pInstance = new LogModule();

        std::thread d(wrapper, s_pInstance);
        d.detach();
    }

    return s_pInstance;
}

void LogModule::LogModule::wrapper(LogModule* pInstance)
{
    //Пока поток не будет разрушен или пока есть очередь сообщений
    while ((!pInstance->m_terminated)> 0)
    {
        if (pInstance->s_deqMessages.size() > 0)
        {
            std::lock_guard<std::recursive_mutex> lock(pInstance->m_logMutex);

            try
            {
                while (pInstance->s_deqMessages.size()>0)
                {
                    auto d = pInstance->s_deqMessages.front();
                    pInstance->s_deqMessages.pop_front();
                    pInstance->write(d.first, d.second);
                }
            }
            catch (const std::exception& ex)
            {
                std::cout << "[Wrapper]: ERROR: " + std::string(ex.what());
            }
        }
        else std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void LogModule::LogModule::write(const std::string& logFileName, const std::string& message)
{
    if (logFileName.size() > 0)
    {
        std::string logPath = "Log";
        std::ofstream streamFile;

        try
        {
#ifdef _WIN32
            _wmkdir(logPath.c_str());
#else
            mkdir(std::string(logPath.begin(), logPath.end()).c_str(), 764);
#endif // _WIN32/Unix

            logPath += "/";
            logPath += logFileName;

#if _WIN32
            streamFile.open(logPath, std::ios::app | std::ios::binary);
#else	//unix
            streamFile.open(std::string(logPath.begin(), logPath.end()).c_str(), std::ios::app | std::ios::binary);

#endif
            const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
            streamFile.imbue(utf8_locale);

            if (streamFile.is_open())
            {
                streamFile << message;
            }

            streamFile.flush();
        }
        catch (const std::exception& ex)
        {
            //NOTHING
            std::cout << "ERROR in LogModule: " << ex.what() << "\n";
        }

        if (streamFile.is_open())
        {
            streamFile.close();
        }
    }
}

std::string LogModule::LogModule::get_time()
{
    std::string retval = "";

    try
    {
        auto dtNow = std::chrono::system_clock::now();
        auto dtTime = std::chrono::system_clock::to_time_t(dtNow);

        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dtNow.time_since_epoch()) -
                std::chrono::duration_cast<std::chrono::seconds>(dtNow.time_since_epoch());

        std::stringstream streamTime{};
        streamTime << std::put_time(std::localtime(&dtTime), "%H:%M:%S.") << std::to_string(ms.count());

        std::string strTime = streamTime.str();

        retval = "[" + strTime.substr(0, strTime.length() - 1) + "]";
    }
    catch (const std::exception& ex)
    {
        retval = "ERROR time";
    }

    return retval;
}

LogModule::LogModule::LogModule()
{
    init();
}

LogModule::LogModule::~LogModule()
{
    dispose();
}

void LogModule::LogModule::write_log(const std::string &logFileName, const std::string &cref_objectInvoker, const std::string &cref_methodInvoker, const std::string &cref_message)
{
    std::lock_guard<std::recursive_mutex> lock(m_logMutex);

    try
    {
        if (!m_terminated)
        {
            if (cref_message.size() > 0)
            {
                try
                {
                    std::string message = get_time() + "[" + cref_objectInvoker
                            + ":" + cref_methodInvoker
                            + "]:\t" + cref_message + "\n";

                    s_deqMessages.push_back(std::pair<std::string, std::string>(logFileName, message));
                }
                catch (const std::exception& ex)
                {
                    //Write ERROR
                    std::cout << "ERROR IN LOGMODULE: " <<  std::string(ex.what()) + "\n";
                }
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << "ERROR in LOGMODULE: "  + std::string(ex.what());
    }
}

void LogModule::LogModule::dispose()
{
    std::lock_guard<std::recursive_mutex> lock(m_logMutex);
    m_terminated = true;
}



