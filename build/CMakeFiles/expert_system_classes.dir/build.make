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
include CMakeFiles/expert_system_classes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/expert_system_classes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/expert_system_classes.dir/flags.make

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o: CMakeFiles/expert_system_classes.dir/flags.make
CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o: ../src/main/utils/tools.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/tools.cpp

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/tools.cpp > CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.i

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/tools.cpp -o CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.s

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.requires:

.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.requires

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.provides: CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.requires
	$(MAKE) -f CMakeFiles/expert_system_classes.dir/build.make CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.provides.build
.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.provides

CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.provides.build: CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o


CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o: CMakeFiles/expert_system_classes.dir/flags.make
CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o: ../src/main/utils/rpn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn.cpp

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn.cpp > CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.i

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn.cpp -o CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.s

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.requires:

.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.requires

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.provides: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.requires
	$(MAKE) -f CMakeFiles/expert_system_classes.dir/build.make CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.provides.build
.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.provides

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.provides.build: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o


CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o: CMakeFiles/expert_system_classes.dir/flags.make
CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o: ../src/main/utils/rpn_conv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn_conv.cpp

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn_conv.cpp > CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.i

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/rpn_conv.cpp -o CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.s

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.requires:

.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.requires

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.provides: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.requires
	$(MAKE) -f CMakeFiles/expert_system_classes.dir/build.make CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.provides.build
.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.provides

CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.provides.build: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o


CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o: CMakeFiles/expert_system_classes.dir/flags.make
CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o: ../src/main/utils/run_program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/run_program.cpp

CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/run_program.cpp > CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.i

CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/run_program.cpp -o CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.s

CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.requires:

.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.requires

CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.provides: CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.requires
	$(MAKE) -f CMakeFiles/expert_system_classes.dir/build.make CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.provides.build
.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.provides

CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.provides.build: CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o


CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o: CMakeFiles/expert_system_classes.dir/flags.make
CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o: ../src/main/utils/error_handling.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o -c /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/error_handling.cpp

CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/error_handling.cpp > CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.i

CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/src/main/utils/error_handling.cpp -o CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.s

CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.requires:

.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.requires

CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.provides: CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.requires
	$(MAKE) -f CMakeFiles/expert_system_classes.dir/build.make CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.provides.build
.PHONY : CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.provides

CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.provides.build: CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o


# Object files for target expert_system_classes
expert_system_classes_OBJECTS = \
"CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o" \
"CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o" \
"CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o" \
"CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o" \
"CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o"

# External object files for target expert_system_classes
expert_system_classes_EXTERNAL_OBJECTS =

../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/build.make
../lib/libexpert_system_classes.a: CMakeFiles/expert_system_classes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library ../lib/libexpert_system_classes.a"
	$(CMAKE_COMMAND) -P CMakeFiles/expert_system_classes.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/expert_system_classes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/expert_system_classes.dir/build: ../lib/libexpert_system_classes.a

.PHONY : CMakeFiles/expert_system_classes.dir/build

CMakeFiles/expert_system_classes.dir/requires: CMakeFiles/expert_system_classes.dir/src/main/utils/tools.cpp.o.requires
CMakeFiles/expert_system_classes.dir/requires: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn.cpp.o.requires
CMakeFiles/expert_system_classes.dir/requires: CMakeFiles/expert_system_classes.dir/src/main/utils/rpn_conv.cpp.o.requires
CMakeFiles/expert_system_classes.dir/requires: CMakeFiles/expert_system_classes.dir/src/main/utils/run_program.cpp.o.requires
CMakeFiles/expert_system_classes.dir/requires: CMakeFiles/expert_system_classes.dir/src/main/utils/error_handling.cpp.o.requires

.PHONY : CMakeFiles/expert_system_classes.dir/requires

CMakeFiles/expert_system_classes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/expert_system_classes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/expert_system_classes.dir/clean

CMakeFiles/expert_system_classes.dir/depend:
	cd /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build /nfs/zfs-student-7/users/sletlape/Documents/Projects/expertsystem/build/CMakeFiles/expert_system_classes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/expert_system_classes.dir/depend

