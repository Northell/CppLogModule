# CMakeList.txt: проект CMake для LogModule; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

set(LOGMODULEPATH_ROOT ../../../../../libs/CppLogModule)
set (LOGMODULEPATH_LIB ../../../../libs/)

# Добавьте источник в исполняемый файл этого проекта.
add_library(${PROJECT} STATIC
#add_executable (LogModule
	"src/LogModule.cpp" "include/LogModule.h"
	 "LogAPI.cpp" "LogAPI.h"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT} PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(${PROJECT}
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

set(installable_libs ${PROJECT})

if(TARGET LogModule)
  list(APPEND installable_libs LogModule)
endif()

install(TARGETS ${installable_libs}
        EXPORT ${PROJECT}Targets
        DESTINATION lib)

install(FILES 
    LogAPI.h
DESTINATION include)

install(FILES 
    include/LogModule.h
DESTINATION include/include)

