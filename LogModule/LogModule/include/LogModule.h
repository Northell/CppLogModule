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
	///		����� ������������� ����������� ��� ������� �����
	/// </summary>
	class LogModule
	{
	private:
		static bool		s_init;					//����, ���������, ����������������� �� ���� ����� ��� ���.
		static bool		s_debugMode;			//���� ��������� ������� �������
		static bool		s_terminated;			//���� ��� ������ ���������
		static std::mutex s_logMutex;			//������� ��������� ������������������� ������ ������

		static std::deque<std::pair<std::wstring, std::wstring>> s_deqMessages;	//������ ������� ���������, ������� ����� �������� � ����.
	
	private:
		static void wrapper();
		static void write(const std::wstring& logFileName, const std::wstring& message);

		static std::wstring get_time();
	
	public:
		static void init();

	public:
		/// <summary>
		///		����� ���������� ����� �������
		/// </summary>
		/// <param name="isDebug">
		///		true - ������� ���������� �����, ��� ���� �������
		///		false - ���������� ����� ��������, ���� �� �������.
		/// </param>
		static void set_debugMode(bool isDebug);

		/// <summary>
		///		����� ����� ����
		/// </summary>
		/// <param name="logFileName"> �������� ����� ��� ������� �����</param>
		/// <param name="objectInvoker">�������� ����������� ������� (��� ���)</param>
		/// <param name="methodInvoker">�������� ����������� ������ (����������� � �����)</param>
		/// <param name="message">����� ���������</param>
		static void write_log(const std::wstring& logFileName, const std::wstring& objectInvoker, const std::wstring& methodInvoker, const std::wstring& message);
	};

}
