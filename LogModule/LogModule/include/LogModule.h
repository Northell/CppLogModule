#pragma once

#include <string>
#include <mutex>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iostream>
#include <locale.h>
#include <codecvt>
#include <deque>
#include <thread>
#include <atomic>
#include <condition_variable>

#ifdef _WIN32
#include <direct.h>
#else 
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include <iomanip>

namespace LogModule
{
/// <summary>
///		The class provide working with logs
/// </summary>
class LogModule
{
private:
    std::unique_ptr<std::deque<std::pair<std::string, std::string>>> _deqRawMessages;        //deq with messages for write in files

    std::atomic<bool>                       _terminated;            //dtor pointer for other threads

    std::mutex                              _mutex;                 //sync primitive
    std::thread                             _wrapperThread;         //Wrapper thread
    std::condition_variable                 _conditionVar_mutex;    //Condition variable for mutex
    bool                                    _isBusy;                //for conditionVar_mutex

private:
    /**
     * @brief wrapper_raw worker deq raw messages
     * @param instance
     */
    static void wrapper_raw(LogModule* instance);

    /**
     * @brief write method write message to log file name
     * @param logFileName
     * @param message
     */
    void write(const std::string& logFileName, const std::string& message);

    /**
     * @brief get_time method returns current time
     * @return
     */
    std::string get_currentTime();

    /**
     * @brief init method executes initialization
     */
    void init();

public:
    LogModule();
    ~LogModule();

    /**
     * @brief write_log method write logs to file
     * @param logFileName log file name
     * @param objectInvoker the object that called this method
     * @param methodInvoker the method that called this method
     * @param message to write
     */
    void write_log(const std::string& logFileName, const std::string& objectInvoker, const std::string& methodInvoker, const std::string& message);

    /**
     * @brief dispose dtor
     */
    void dispose();
};

}
