# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build"

# Include any dependencies generated for this target.
include CMakeFiles/run_all_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_all_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_all_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_all_tests.dir/flags.make

CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o: CMakeFiles/run_all_tests.dir/flags.make
CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o: /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_quicksort.cpp
CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o: CMakeFiles/run_all_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o -MF CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o.d -o CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o -c "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_quicksort.cpp"

CMakeFiles/run_all_tests.dir/test_quicksort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_all_tests.dir/test_quicksort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_quicksort.cpp" > CMakeFiles/run_all_tests.dir/test_quicksort.cpp.i

CMakeFiles/run_all_tests.dir/test_quicksort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_all_tests.dir/test_quicksort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_quicksort.cpp" -o CMakeFiles/run_all_tests.dir/test_quicksort.cpp.s

CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o: CMakeFiles/run_all_tests.dir/flags.make
CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o: /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_insertionsort.cpp
CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o: CMakeFiles/run_all_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o -MF CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o.d -o CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o -c "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_insertionsort.cpp"

CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_insertionsort.cpp" > CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.i

CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_insertionsort.cpp" -o CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.s

CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o: CMakeFiles/run_all_tests.dir/flags.make
CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o: /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_bubblesort.cpp
CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o: CMakeFiles/run_all_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o -MF CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o.d -o CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o -c "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_bubblesort.cpp"

CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_bubblesort.cpp" > CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.i

CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_bubblesort.cpp" -o CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.s

CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o: CMakeFiles/run_all_tests.dir/flags.make
CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o: /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_mpointer.cpp
CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o: CMakeFiles/run_all_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o -MF CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o.d -o CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o -c "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_mpointer.cpp"

CMakeFiles/run_all_tests.dir/test_mpointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_all_tests.dir/test_mpointer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_mpointer.cpp" > CMakeFiles/run_all_tests.dir/test_mpointer.cpp.i

CMakeFiles/run_all_tests.dir/test_mpointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_all_tests.dir/test_mpointer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_mpointer.cpp" -o CMakeFiles/run_all_tests.dir/test_mpointer.cpp.s

CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o: CMakeFiles/run_all_tests.dir/flags.make
CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o: /home/fabricio/Documents/Prueba\ C/Proyecto1-main/PruebasUnitarias/test_doubly_linked_list.cpp
CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o: CMakeFiles/run_all_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o -MF CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o.d -o CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o -c "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_doubly_linked_list.cpp"

CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_doubly_linked_list.cpp" > CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.i

CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/test_doubly_linked_list.cpp" -o CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.s

# Object files for target run_all_tests
run_all_tests_OBJECTS = \
"CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o" \
"CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o" \
"CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o" \
"CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o" \
"CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o"

# External object files for target run_all_tests
run_all_tests_EXTERNAL_OBJECTS =

run_all_tests: CMakeFiles/run_all_tests.dir/test_quicksort.cpp.o
run_all_tests: CMakeFiles/run_all_tests.dir/test_insertionsort.cpp.o
run_all_tests: CMakeFiles/run_all_tests.dir/test_bubblesort.cpp.o
run_all_tests: CMakeFiles/run_all_tests.dir/test_mpointer.cpp.o
run_all_tests: CMakeFiles/run_all_tests.dir/test_doubly_linked_list.cpp.o
run_all_tests: CMakeFiles/run_all_tests.dir/build.make
run_all_tests: /usr/lib/x86_64-linux-gnu/libgtest.a
run_all_tests: CMakeFiles/run_all_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable run_all_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_all_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_all_tests.dir/build: run_all_tests
.PHONY : CMakeFiles/run_all_tests.dir/build

CMakeFiles/run_all_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_all_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_all_tests.dir/clean

CMakeFiles/run_all_tests.dir/depend:
	cd "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias" "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias" "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build" "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build" "/home/fabricio/Documents/Prueba C/Proyecto1-main/PruebasUnitarias/build/CMakeFiles/run_all_tests.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/run_all_tests.dir/depend

