#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "CppLogModule" for configuration "Debug"
set_property(TARGET CppLogModule APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(CppLogModule PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/../../../../../libs/CppLogModule/lib/CppLogModule.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/../../../../../libs/CppLogModule/lib/CppLogModule.dll"
  )

list(APPEND _cmake_import_check_targets CppLogModule )
list(APPEND _cmake_import_check_files_for_CppLogModule "${_IMPORT_PREFIX}/../../../../../libs/CppLogModule/lib/CppLogModule.lib" "${_IMPORT_PREFIX}/../../../../../libs/CppLogModule/lib/CppLogModule.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
