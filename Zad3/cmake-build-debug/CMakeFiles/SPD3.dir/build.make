# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/mrhowever/Programs/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mrhowever/Programs/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrhowever/Programming/Projects/SPD3/Zad3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SPD3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPD3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPD3.dir/flags.make

CMakeFiles/SPD3.dir/Controller.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/Controller.cpp.o: ../Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPD3.dir/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/Controller.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/Controller.cpp

CMakeFiles/SPD3.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/Controller.cpp > CMakeFiles/SPD3.dir/Controller.cpp.i

CMakeFiles/SPD3.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/Controller.cpp -o CMakeFiles/SPD3.dir/Controller.cpp.s

CMakeFiles/SPD3.dir/Machine.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/Machine.cpp.o: ../Machine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SPD3.dir/Machine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/Machine.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/Machine.cpp

CMakeFiles/SPD3.dir/Machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/Machine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/Machine.cpp > CMakeFiles/SPD3.dir/Machine.cpp.i

CMakeFiles/SPD3.dir/Machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/Machine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/Machine.cpp -o CMakeFiles/SPD3.dir/Machine.cpp.s

CMakeFiles/SPD3.dir/main.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SPD3.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/main.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/main.cpp

CMakeFiles/SPD3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/main.cpp > CMakeFiles/SPD3.dir/main.cpp.i

CMakeFiles/SPD3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/main.cpp -o CMakeFiles/SPD3.dir/main.cpp.s

CMakeFiles/SPD3.dir/Task.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/Task.cpp.o: ../Task.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SPD3.dir/Task.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/Task.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/Task.cpp

CMakeFiles/SPD3.dir/Task.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/Task.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/Task.cpp > CMakeFiles/SPD3.dir/Task.cpp.i

CMakeFiles/SPD3.dir/Task.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/Task.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/Task.cpp -o CMakeFiles/SPD3.dir/Task.cpp.s

CMakeFiles/SPD3.dir/Scheduler.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/Scheduler.cpp.o: ../Scheduler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SPD3.dir/Scheduler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/Scheduler.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/Scheduler.cpp

CMakeFiles/SPD3.dir/Scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/Scheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/Scheduler.cpp > CMakeFiles/SPD3.dir/Scheduler.cpp.i

CMakeFiles/SPD3.dir/Scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/Scheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/Scheduler.cpp -o CMakeFiles/SPD3.dir/Scheduler.cpp.s

CMakeFiles/SPD3.dir/Node.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/Node.cpp.o: ../Node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SPD3.dir/Node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/Node.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/Node.cpp

CMakeFiles/SPD3.dir/Node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/Node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/Node.cpp > CMakeFiles/SPD3.dir/Node.cpp.i

CMakeFiles/SPD3.dir/Node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/Node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/Node.cpp -o CMakeFiles/SPD3.dir/Node.cpp.s

CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o: ../FlowshopGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/FlowshopGraph.cpp

CMakeFiles/SPD3.dir/FlowshopGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/FlowshopGraph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/FlowshopGraph.cpp > CMakeFiles/SPD3.dir/FlowshopGraph.cpp.i

CMakeFiles/SPD3.dir/FlowshopGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/FlowshopGraph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/FlowshopGraph.cpp -o CMakeFiles/SPD3.dir/FlowshopGraph.cpp.s

CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o: ../OrderingAlgorithm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/OrderingAlgorithm.cpp

CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/OrderingAlgorithm.cpp > CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.i

CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/OrderingAlgorithm.cpp -o CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.s

CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o: ../JohnsonOrder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/JohnsonOrder.cpp

CMakeFiles/SPD3.dir/JohnsonOrder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/JohnsonOrder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/JohnsonOrder.cpp > CMakeFiles/SPD3.dir/JohnsonOrder.cpp.i

CMakeFiles/SPD3.dir/JohnsonOrder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/JohnsonOrder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/JohnsonOrder.cpp -o CMakeFiles/SPD3.dir/JohnsonOrder.cpp.s

CMakeFiles/SPD3.dir/NEHOrder.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/NEHOrder.cpp.o: ../NEHOrder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SPD3.dir/NEHOrder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/NEHOrder.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/NEHOrder.cpp

CMakeFiles/SPD3.dir/NEHOrder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/NEHOrder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/NEHOrder.cpp > CMakeFiles/SPD3.dir/NEHOrder.cpp.i

CMakeFiles/SPD3.dir/NEHOrder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/NEHOrder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/NEHOrder.cpp -o CMakeFiles/SPD3.dir/NEHOrder.cpp.s

CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o: CMakeFiles/SPD3.dir/flags.make
CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o: ../SimulatedAnnealing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o -c /home/mrhowever/Programming/Projects/SPD3/Zad3/SimulatedAnnealing.cpp

CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrhowever/Programming/Projects/SPD3/Zad3/SimulatedAnnealing.cpp > CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.i

CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrhowever/Programming/Projects/SPD3/Zad3/SimulatedAnnealing.cpp -o CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.s

# Object files for target SPD3
SPD3_OBJECTS = \
"CMakeFiles/SPD3.dir/Controller.cpp.o" \
"CMakeFiles/SPD3.dir/Machine.cpp.o" \
"CMakeFiles/SPD3.dir/main.cpp.o" \
"CMakeFiles/SPD3.dir/Task.cpp.o" \
"CMakeFiles/SPD3.dir/Scheduler.cpp.o" \
"CMakeFiles/SPD3.dir/Node.cpp.o" \
"CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o" \
"CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o" \
"CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o" \
"CMakeFiles/SPD3.dir/NEHOrder.cpp.o" \
"CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o"

# External object files for target SPD3
SPD3_EXTERNAL_OBJECTS =

SPD3: CMakeFiles/SPD3.dir/Controller.cpp.o
SPD3: CMakeFiles/SPD3.dir/Machine.cpp.o
SPD3: CMakeFiles/SPD3.dir/main.cpp.o
SPD3: CMakeFiles/SPD3.dir/Task.cpp.o
SPD3: CMakeFiles/SPD3.dir/Scheduler.cpp.o
SPD3: CMakeFiles/SPD3.dir/Node.cpp.o
SPD3: CMakeFiles/SPD3.dir/FlowshopGraph.cpp.o
SPD3: CMakeFiles/SPD3.dir/OrderingAlgorithm.cpp.o
SPD3: CMakeFiles/SPD3.dir/JohnsonOrder.cpp.o
SPD3: CMakeFiles/SPD3.dir/NEHOrder.cpp.o
SPD3: CMakeFiles/SPD3.dir/SimulatedAnnealing.cpp.o
SPD3: CMakeFiles/SPD3.dir/build.make
SPD3: CMakeFiles/SPD3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable SPD3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPD3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPD3.dir/build: SPD3

.PHONY : CMakeFiles/SPD3.dir/build

CMakeFiles/SPD3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPD3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPD3.dir/clean

CMakeFiles/SPD3.dir/depend:
	cd /home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrhowever/Programming/Projects/SPD3/Zad3 /home/mrhowever/Programming/Projects/SPD3/Zad3 /home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug /home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug /home/mrhowever/Programming/Projects/SPD3/Zad3/cmake-build-debug/CMakeFiles/SPD3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPD3.dir/depend

