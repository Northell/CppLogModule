# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

set (PROJECT CppLogModule)

set(CMAKE_CXX_STANDARD 17)             # Стандарт C++
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CPPLOGMODULE_ROOT libs/CppLogModule)
set (CMAKE_BINARY_DIR out)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CppLogModule")
#project ("LogModule_Test")

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

  macro(copy_directory _src _dst)

    if (EXISTS ${_dst})
        file(REMOVE_RECURSE ${_dst})
    endif ()

    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${_src} ${_dst}
        RESULT_VARIABLE _res
        OUTPUT_VARIABLE _out
        ERROR_VARIABLE  _err
    )

    if(_err)
        message(FATAL_ERROR "ERROR ---> could not be copied: ${_err}")
    endif()
endmacro()

copy_directory(${CMAKE_CURRENT_SOURCE_DIR}/out/install ${CPPLOGMODULE_ROOT}/install)
