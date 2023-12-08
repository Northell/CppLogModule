#include "LogAPI.h"
// LogModule.cpp: определяет точку входа для приложения.
//
#pragma once
#include <iostream>
#include "LogAPI.h"
#include <locale.h>

void LogModule::write_log(const wchar_t* pathToFile, const wchar_t* classInvoker, const wchar_t* methodInvoker, const wchar_t* message)
{
	setlocale(LC_ALL, "ru");
	LogModule::init();

	//std::wcout << pathToFile << "\t" << classInvoker << "\t" << methodInvoker << "\t" << message << "\n\n";

	//Логгируем
	LogModule::write_log(pathToFile, classInvoker, methodInvoker, message);
}

void LogModule::write_log(const std::string& cref_logFileName, const std::string& cref_classInvoker, const std::string& cref_methodInvoker, const std::string& cref_message)
{
	std::wstring logFileName = std::wstring(cref_logFileName.begin(), cref_logFileName.end());
	std::wstring classInvoker = std::wstring(cref_classInvoker.begin(), cref_classInvoker.end());
	std::wstring methodInvoker = std::wstring(cref_methodInvoker.begin(), cref_methodInvoker.end());
	std::wstring message = std::wstring(cref_message.begin(), cref_message.end());

	write_log(logFileName.c_str(), classInvoker.c_str(), methodInvoker.c_str(), message.c_str());
}

void LogModule::set_debug(bool isDebug)
{
	LogModule::set_debugMode(isDebug);
}
