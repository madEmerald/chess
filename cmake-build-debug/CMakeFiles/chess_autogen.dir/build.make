# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CLionProjects\chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CLionProjects\chess\cmake-build-debug

# Utility rule file for chess_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/chess_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/chess_autogen.dir/progress.make

CMakeFiles/chess_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target chess"
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E cmake_autogen C:/CLionProjects/chess/cmake-build-debug/CMakeFiles/chess_autogen.dir/AutogenInfo.json Debug

chess_autogen: CMakeFiles/chess_autogen
chess_autogen: CMakeFiles/chess_autogen.dir/build.make
.PHONY : chess_autogen

# Rule to build all files generated by this target.
CMakeFiles/chess_autogen.dir/build: chess_autogen
.PHONY : CMakeFiles/chess_autogen.dir/build

CMakeFiles/chess_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess_autogen.dir/clean

CMakeFiles/chess_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CLionProjects\chess C:\CLionProjects\chess C:\CLionProjects\chess\cmake-build-debug C:\CLionProjects\chess\cmake-build-debug C:\CLionProjects\chess\cmake-build-debug\CMakeFiles\chess_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess_autogen.dir/depend

