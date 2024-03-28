add_library(${PROJECT} STATIC
    #add_executable (LogModule
    "src/LogModule.cpp" "include/LogModule.h"
    "LogAPI.cpp" "LogAPI.h"
    "LogAPI_global.h"
    )

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


