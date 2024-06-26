﻿# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.3)

set (PROJECT CppLogModule)

set(CMAKE_CXX_STANDARD 17)             # Стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

set(CPPLOGMODULE_ROOT /libs/CppLogModule)

if (UNIX)
    set(TYPE_LIB STATIC)
else()
    set(TYPE_LIB SHARED)
endif()

project ("CppLogModule" LANGUAGES CXX)

# Включите подпроекты.
add_subdirectory(LogModule)
#add_subdirectory(Tests)

install(EXPORT CppLogModuleTargets
    FILE CppLogModuleTargets.cmake
    DESTINATION lib/cmake
)

include(CMakePackageConfigHelpers)

# generate the config file that includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/CppLogModuleConfig.cmake"
    INSTALL_DESTINATION lib/cmake/CppLogModule
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/CppLogModuleConfigVersion.cmake"
    VERSION "${CppLogModule_VERSION_MAJOR}.${CppLogModule_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/CppLogModuleConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/CppLogModuleConfigVersion.cmake
    DESTINATION lib/cmake
)

export(EXPORT CppLogModuleTargets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/CppLogModuleTargets.cmake"
)
