#include <gtest/gtest.h>

#include <iostream>
#include "../../LogModule/LogAPI.h"
#include <thread>
#include <vector>

TEST(LogModule_Test, Test_LogModule)
{
	LogModule::set_debug(true);

    auto d = [](int numThread) {
        for (int j = 0; j < 1000; ++j)
		{
			try
			{
				std::stringstream ss;
				ss << std::this_thread::get_id();
				int id;
				ss >> id;

                LogModule::write_log("log_test", "Thread", "TEST", "Test thread" + std::to_string(numThread) + ": " + std::to_string(j)
					+ ", std::threadID = " + std::to_string(id));
			}
			catch (const std::exception& ex)
			{
				std::cout << "\n\n" << ex.what();
			}
		}
		};

    std::vector<std::thread*> threads;

    for(int i =0; i< 100; ++i)
    {
        std::thread* th = new std::thread(d, i);
        threads.push_back(th);
        th->detach();
    }

	std::this_thread::sleep_for(std::chrono::milliseconds(10000));

	for (int i = 0; i < threads.size(); ++i)
	{
		delete threads[i];
	}
}
