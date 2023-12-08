#include <gtest/gtest.h>

#include <iostream>
#include "../../LogModule/LogAPI.h"
#include <thread>
#include <vector>

TEST(LogModule_Test, Test_LogModule)
{
	LogModule::set_debug(true);

	auto d = []() {
		for (int j = 0; j < 100; ++j)
		{
			try
			{
				std::stringstream ss;
				ss << std::this_thread::get_id();
				int id;
				ss >> id;

				LogModule::write_log("log_test", "Thread", "TEST", "Test j = " + std::to_string(j)
					+ ", std::threadID = " + std::to_string(id));
			}
			catch (const std::exception& ex)
			{
				std::cout << "\n\n" << ex.what();
			}
		}
		};

	std::vector<std::thread*> threads{
		new std::thread(d)
		, new std::thread(d)
		,new  std::thread(d)
		, new std::thread(d)
	};

	for (int i = 0; i < threads.size(); ++i)
	{
		threads.at(i)->detach();
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	for (int i = 0; i < threads.size(); ++i)
	{
		delete threads[i];
	}
}