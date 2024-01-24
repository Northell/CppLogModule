# Install script for directory: C:/share/Code/CppModules/CppLogModule/LogModule

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/share/Code/CppModules/CppLogModule/LogModule/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule/CppLogModule.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule/CppLogModule.cmake"
         "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/CMakeFiles/Export/8b529adc5c9aa5ed1e7582c80a24a6e8/CppLogModule.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule/CppLogModule-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule/CppLogModule.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule" TYPE FILE FILES "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/CMakeFiles/Export/8b529adc5c9aa5ed1e7582c80a24a6e8/CppLogModule.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake/CppLogModule" TYPE FILE FILES "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/CMakeFiles/Export/8b529adc5c9aa5ed1e7582c80a24a6e8/CppLogModule-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/../../../../../libs/CppLogModule/lib/cmake" TYPE FILE FILES
    "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/CppLogModuleConfig.cmake"
    "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/CppLogModuleConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/LogModule/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/share/Code/CppModules/CppLogModule/LogModule/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
