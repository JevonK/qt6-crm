# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /Volumes/anjie/MacApp/Qt/Tools/CMake/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Volumes/anjie/MacApp/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/anjie/Project/C++/crm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Utility rule file for crm_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/crm_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/crm_autogen.dir/progress.make

CMakeFiles/crm_autogen: crm_autogen/timestamp

crm_autogen/timestamp: /Volumes/anjie/MacApp/Qt/6.7.2/macos/./libexec/moc
crm_autogen/timestamp: /Volumes/anjie/MacApp/Qt/6.7.2/macos/./libexec/uic
crm_autogen/timestamp: CMakeFiles/crm_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target crm"
	/Volumes/anjie/MacApp/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E cmake_autogen /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/crm_autogen.dir/AutogenInfo.json Debug
	/Volumes/anjie/MacApp/Qt/Tools/CMake/CMake.app/Contents/bin/cmake -E touch /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/crm_autogen/timestamp

crm_autogen: CMakeFiles/crm_autogen
crm_autogen: crm_autogen/timestamp
crm_autogen: CMakeFiles/crm_autogen.dir/build.make
.PHONY : crm_autogen

# Rule to build all files generated by this target.
CMakeFiles/crm_autogen.dir/build: crm_autogen
.PHONY : CMakeFiles/crm_autogen.dir/build

CMakeFiles/crm_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/crm_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/crm_autogen.dir/clean

CMakeFiles/crm_autogen.dir/depend:
	cd /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/anjie/Project/C++/crm /Volumes/anjie/Project/C++/crm /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug /Volumes/anjie/Project/C++/crm/build/Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/crm_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/crm_autogen.dir/depend

