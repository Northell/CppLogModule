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
        static bool         s_init;					//Флаг указывает, что прошла инициализация и можно работать
        static bool         s_terminated;			//Указатель к разрушению
        static std::mutex   s_logMutex;             //Блокирует файл на запись

        static std::deque<std::pair<std::wstring, std::wstring>> s_deqMessages;	//Очередь сообщений, которую обрабатывает поток
	
	private:
		static void wrapper();
		static void write(const std::wstring& logFileName, const std::wstring& message);

		static std::wstring get_time();
	
	public:
		static void init();

    public:
		/// <summary>
        ///		Метод пишет логи в файл
		/// </summary>
        /// <param name="logFileName"> Файл для записи логов</param>
        /// <param name="objectInvoker">Класс, который вызывает логгер</param>
        /// <param name="methodInvoker">Метод, из которого осуществляется запись</param>
        /// <param name="message">Сообщение, которое нужно записать в логи</param>
		static void write_log(const std::wstring& logFileName, const std::wstring& objectInvoker, const std::wstring& methodInvoker, const std::wstring& message);

        /**
         * @brief dispose destructor
         */
        static void dispose();
	};

}
