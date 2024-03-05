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
///		Класс осуществляет работу с логами
/// </summary>
class LogModule
{

private:
    static LogModule*   s_pInstance;

    bool                    m_terminated;			//Указатель к разрушению
    std::recursive_mutex    m_logMutex;             //Блокирует файл на запись
    //std::unique_lock<std::mutex> locker;             //RAII mutex

    std::deque<std::pair<std::string, std::string>> s_deqMessages;	//Очередь сообщений, которую обрабатывает поток

private:
    static void wrapper(LogModule* instance);
    void write(const std::string& logFileName, const std::string& message);

    std::string get_time();

protected:
    LogModule();
    ~LogModule();

public:
    static LogModule* get_instance();
    void init();

    void write_log(const std::string& logFileName, const std::string& objectInvoker, const std::string& methodInvoker, const std::string& message);
    void dispose();
};

}
