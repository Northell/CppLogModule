# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule

# Include any dependencies generated for this target.
include LogModule/CMakeFiles/CppLogModule.dir/depend.make

# Include the progress variables for this target.
include LogModule/CMakeFiles/CppLogModule.dir/progress.make

# Include the compile flags for this target's objects.
include LogModule/CMakeFiles/CppLogModule.dir/flags.make

LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o: LogModule/CMakeFiles/CppLogModule.dir/flags.make
LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o: LogModule/src/LogModule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o -c /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/src/LogModule.cpp

LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppLogModule.dir/src/LogModule.cpp.i"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/src/LogModule.cpp > CMakeFiles/CppLogModule.dir/src/LogModule.cpp.i

LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppLogModule.dir/src/LogModule.cpp.s"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/src/LogModule.cpp -o CMakeFiles/CppLogModule.dir/src/LogModule.cpp.s

LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.o: LogModule/CMakeFiles/CppLogModule.dir/flags.make
LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.o: LogModule/LogAPI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.o"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppLogModule.dir/LogAPI.cpp.o -c /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/LogAPI.cpp

LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppLogModule.dir/LogAPI.cpp.i"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/LogAPI.cpp > CMakeFiles/CppLogModule.dir/LogAPI.cpp.i

LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppLogModule.dir/LogAPI.cpp.s"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/LogAPI.cpp -o CMakeFiles/CppLogModule.dir/LogAPI.cpp.s

# Object files for target CppLogModule
CppLogModule_OBJECTS = \
"CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o" \
"CMakeFiles/CppLogModule.dir/LogAPI.cpp.o"

# External object files for target CppLogModule
CppLogModule_EXTERNAL_OBJECTS =

LogModule/libCppLogModule.a: LogModule/CMakeFiles/CppLogModule.dir/src/LogModule.cpp.o
LogModule/libCppLogModule.a: LogModule/CMakeFiles/CppLogModule.dir/LogAPI.cpp.o
LogModule/libCppLogModule.a: LogModule/CMakeFiles/CppLogModule.dir/build.make
LogModule/libCppLogModule.a: LogModule/CMakeFiles/CppLogModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libCppLogModule.a"
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && $(CMAKE_COMMAND) -P CMakeFiles/CppLogModule.dir/cmake_clean_target.cmake
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppLogModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
LogModule/CMakeFiles/CppLogModule.dir/build: LogModule/libCppLogModule.a

.PHONY : LogModule/CMakeFiles/CppLogModule.dir/build

LogModule/CMakeFiles/CppLogModule.dir/clean:
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule && $(CMAKE_COMMAND) -P CMakeFiles/CppLogModule.dir/cmake_clean.cmake
.PHONY : LogModule/CMakeFiles/CppLogModule.dir/clean

LogModule/CMakeFiles/CppLogModule.dir/depend:
	cd /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule /home/nrt/Desktops/Desktop1/share/Code/CppLogModule/LogModule/LogModule/CMakeFiles/CppLogModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : LogModule/CMakeFiles/CppLogModule.dir/depend

