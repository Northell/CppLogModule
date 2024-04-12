#include "../include/LogModule.h"
void LogModule::LogModule::init()
{
    _terminated = false;

    _deqRawMessages = std::make_unique<std::deque<std::pair<std::string, std::string>>>();

    _wrapperThread = std::thread (&LogModule::wrapper_raw, this);
}

void LogModule::LogModule::wrapper_raw(LogModule* pInstance)
{
    while ((pInstance !=nullptr) && ((!pInstance->_terminated)> 0))
    {
        try
        {
            if ((pInstance->_deqRawMessages->size()>0))
            {
                std::unique_ptr<std::deque<std::pair<std::string, std::string>>> deq;

                std::unique_lock<std::mutex> lock(pInstance->_mutex);
                pInstance->_isBusy = true;

                std::this_thread::sleep_for(std::chrono::milliseconds(10));

                try
                {
                    deq = std::move(pInstance->_deqRawMessages);
                    pInstance->_deqRawMessages = std::make_unique<std::deque<std::pair<std::string, std::string>>>();
                }
                catch (...)
                {
                    //NOTHING
                }

                pInstance->_isBusy = false;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));

                pInstance->_isBusy = false;

                lock.unlock();
                pInstance->_conditionVar_mutex.notify_all();

                if (deq!= nullptr)
                {
                    while (!deq->empty())
                    {
                        if ((deq->front().first.size()>0)
                            && (deq->front().second.size()>0))
                        {
                            pInstance->write(deq->front().first, deq->front().second);

                            deq->pop_front();
                        }
                    }

                    deq.reset();
                }
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << "[Wrapper_raw]: ERROR: " + std::string(ex.what());

            if (pInstance->_isBusy)
            {
                pInstance->_isBusy = false;
                pInstance->_conditionVar_mutex.notify_all();
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
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
#ifdef __unix
            mkdir(logPath.c_str(), 764);
#else
            mkdir(logPath.c_str());
#endif
            logPath += "/"+logFileName;

            streamFile.open(logPath, std::ios::app | std::ios::binary);

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

std::string LogModule::LogModule::get_currentTime()
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

        if (strTime.size()>0)
        {
            retval = "[" + strTime.substr(0, strTime.length() - 1) + "]";
        }
        else throw std::exception();
    }
    catch (const std::exception& ex)
    {
        retval = "ERROR time";
    }

    return retval;
}

LogModule::LogModule::LogModule()
    : _isBusy(false)
{
    init();
}

LogModule::LogModule::~LogModule()
{
    dispose();

    _wrapperThread.join();
}

void LogModule::LogModule::write_log(const std::string& logFileName, const std::string &cref_objectInvoker, const std::string &cref_methodInvoker, const std::string &cref_message)
{

    if (!_terminated)
    {
        try
        {
            if (cref_message.size() > 0)
            {

                std::unique_lock<std::mutex> lock(_mutex);
                _conditionVar_mutex.wait(lock, [&]{ return !_isBusy;});

                std::string message = get_currentTime() + "[" + cref_objectInvoker
                        + ":" + cref_methodInvoker
                        + "]:\t" + cref_message + "\n";

                _deqRawMessages->push_back(std::make_pair(logFileName, message));

                lock.unlock();
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << "ERROR in LOGMODULE: "  + std::string(ex.what());

            if (_isBusy)
            {
                _isBusy = false;
            }
        }
    }
}

void LogModule::LogModule::dispose()
{
    _terminated = true;
}
