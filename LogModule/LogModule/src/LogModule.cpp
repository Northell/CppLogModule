#include "../include/LogModule.h"

bool LogModule::LogModule::s_init = false;
bool LogModule::LogModule::s_terminated = false;
bool LogModule::LogModule::s_debugMode = false;
std::deque<std::pair<std::wstring, std::wstring>> LogModule::LogModule::s_deqMessages;

std::mutex  LogModule::LogModule::s_logMutex;

void LogModule::LogModule::init()
{
	if (!s_init)
	{
		std::thread d(wrapper);
		d.detach();
		s_init = true;
	}
}

void LogModule::LogModule::wrapper()
{
	//Поток пишет логи
	while ((!s_terminated)
		|| (s_deqMessages.size()>0))
	{
		try
		{
			if (s_deqMessages.size() > 0)
			{
				std::scoped_lock lock(s_logMutex);

				auto& it = s_deqMessages.front();
				write(it.first, it.second);
				s_deqMessages.pop_front();
			}
			else std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		catch (const std::exception& ex)
		{
			std::cout << "[Wrapper]: ERROR: " + std::string(ex.what());
		}
	}
}

void LogModule::LogModule::write(const std::wstring& logFileName, const std::wstring& message)
{
	if (logFileName.size() > 0)
	{
		std::wstring logPath = L"Log";
		std::wofstream streamFile;

		try
		{
	#ifdef _WIN32
			_wmkdir(logPath.c_str());
	#else
			mkdir(logPath.c_str(), 764);
	#endif // _WIN32/Unix

			logPath += L"/";
			logPath += logFileName;
			streamFile.open(logPath, std::ios::app | std::ios::binary);
			const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
			streamFile.imbue(utf8_locale);

			if (streamFile.is_open())
			{
				streamFile << message;
			}
		}
		catch (std::exception ex)
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

std::wstring LogModule::LogModule::get_time()
{
	auto dtNow = std::chrono::system_clock::now();
	auto dtTime = std::chrono::system_clock::to_time_t(dtNow);

	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dtNow.time_since_epoch()) -
		std::chrono::duration_cast<std::chrono::seconds>(dtNow.time_since_epoch());

	std::wstringstream streamTime{};
	streamTime << std::put_time(std::localtime(&dtTime), L"%H:%M:%S.") << std::to_wstring(ms.count());
	std::wstring strTime = streamTime.str();

	std::wstring retval = L"[" + strTime.substr(0, strTime.length() - 1) + L"]";

	return retval;
}

void LogModule::LogModule::set_debugMode(bool isDebug)
{
	s_debugMode = isDebug;
}

void  LogModule::LogModule::write_log(const std::wstring& cref_strLogFileName, const std::wstring& cref_strObjectInvoker,
	const std::wstring& cref_strMethodInvoker, const std::wstring& cref_strMessage)
{
	if (s_debugMode)
	{ 
		if (!s_terminated)
		{
			try
			{
				if (cref_strMessage.size() > 0)
				{
					std::scoped_lock lock(s_logMutex);

					init();

					std::wstring logFileName = cref_strLogFileName;
					std::wstring objectInvoker = std::wstring(cref_strObjectInvoker);
					std::wstring methodInvoker = std::wstring(cref_strMethodInvoker);
					std::wstring logMessage = std::wstring(cref_strMessage);

					std::wstring message = get_time() + L"[" + std::wstring(objectInvoker.begin(), objectInvoker.end())
						+ L"::" + std::wstring(methodInvoker.begin(), methodInvoker.end())
						+ L"]:\t" + std::wstring(logMessage.begin(), logMessage.end()).c_str() + L";\n";

					s_deqMessages.push_back(std::pair<std::wstring, std::wstring>(logFileName, message));
				}
			}
			catch (const std::exception& ex)
			{
				//Логгируем
				std::wcout << ex.what();
			}
		}
	}
}


