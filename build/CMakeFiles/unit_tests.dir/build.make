# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /nfs/zfs-student-7/users/sletlape/.brew/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /nfs/zfs-student-7/users/sletlape/.brew/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build

# Include any dependencies generated for this target.
include CMakeFiles/unit_tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unit_tests.dir/flags.make

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o: CMakeFiles/unit_tests.dir/flags.make
CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o: ../src/test/unit_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/test/unit_tests.cpp

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/test/unit_tests.cpp > CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.i

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/test/unit_tests.cpp -o CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.s

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.requires:

.PHONY : CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.requires

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.provides: CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.requires
	$(MAKE) -f CMakeFiles/unit_tests.dir/build.make CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.provides.build
.PHONY : CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.provides

CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.provides.build: CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o


# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS =

../bin/unit_tests: CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o
../bin/unit_tests: CMakeFiles/unit_tests.dir/build.make
../bin/unit_tests: ../lib/libexpert_system_classes.a
../bin/unit_tests: CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/unit_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unit_tests.dir/build: ../bin/unit_tests

.PHONY : CMakeFiles/unit_tests.dir/build

CMakeFiles/unit_tests.dir/requires: CMakeFiles/unit_tests.dir/src/test/unit_tests.cpp.o.requires

.PHONY : CMakeFiles/unit_tests.dir/requires

CMakeFiles/unit_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unit_tests.dir/clean

CMakeFiles/unit_tests.dir/depend:
	cd /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unit_tests.dir/depend

