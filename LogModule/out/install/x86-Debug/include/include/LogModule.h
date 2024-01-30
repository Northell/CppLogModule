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
#include <direct.h>


namespace LogModule
{
	/// <summary>
	///		Класс предоставляет инструменты для ведения логов
	/// </summary>
	class LogModule
	{
	private:
		static bool		s_init;					//Флаг, указывает, проинициализрован ли этот класс или нет.
		static bool		s_debugMode;			//Флаг управляет режимом отладки
		static bool		s_terminated;			//Флаг для потока обработки
		static std::mutex s_logMutex;			//Мьютекс управляет потокобезопасностью внутри класса

		static std::deque<std::pair<std::wstring, std::wstring>> s_deqMessages;	//Хранит очередь сообщений, которую нужно записать в файл.
	
	private:
		static void wrapper();
		static void write(const std::wstring& logFileName, const std::wstring& message);

		static std::wstring get_time();
	
	public:
		static void init();

	public:
		/// <summary>
		///		Метод выставляет режим отладки
		/// </summary>
		/// <param name="isDebug">
		///		true - включен отладочный режим, все логи ведутся
		///		false - отладочный режим выключен, логи не ведутся.
		/// </param>
		static void set_debugMode(bool isDebug);

		/// <summary>
		///		Метод ведет логи
		/// </summary>
		/// <param name="logFileName"> Название файла для ведения логов</param>
		/// <param name="objectInvoker">Название вызывающего объекта (или тип)</param>
		/// <param name="methodInvoker">Название вызывающего метода (Отобразится в логах)</param>
		/// <param name="message">Текст сообщения</param>
		static void write_log(const std::wstring& logFileName, const std::wstring& objectInvoker, const std::wstring& methodInvoker, const std::wstring& message);
	};

}
