
include_directories(CppLogModule)

#GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

#==========================

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
# GTest
enable_testing()


add_executable(LogModule_Test "src/LogModule_Test.cpp")
target_link_libraries(LogModule_Test GTest::gtest_main)
target_link_libraries(LogModule_Test CppLogModule)

include(GoogleTest)
gtest_discover_tests(LogModule_Test)
