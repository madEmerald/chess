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

# Include any dependencies generated for this target.
include CMakeFiles/chess.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chess.dir/flags.make

CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj: chess_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\chess_autogen\mocs_compilation.cpp.obj -c C:\CLionProjects\chess\cmake-build-debug\chess_autogen\mocs_compilation.cpp

CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\cmake-build-debug\chess_autogen\mocs_compilation.cpp > CMakeFiles\chess.dir\chess_autogen\mocs_compilation.cpp.i

CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\cmake-build-debug\chess_autogen\mocs_compilation.cpp -o CMakeFiles\chess.dir\chess_autogen\mocs_compilation.cpp.s

CMakeFiles/chess.dir/main.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/main.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/chess.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\main.cpp.obj -c C:\CLionProjects\chess\main.cpp

CMakeFiles/chess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\main.cpp > CMakeFiles\chess.dir\main.cpp.i

CMakeFiles/chess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\main.cpp -o CMakeFiles\chess.dir\main.cpp.s

CMakeFiles/chess.dir/mainwindow.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/mainwindow.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/mainwindow.cpp.obj: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/chess.dir/mainwindow.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\mainwindow.cpp.obj -c C:\CLionProjects\chess\mainwindow.cpp

CMakeFiles/chess.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/mainwindow.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\mainwindow.cpp > CMakeFiles\chess.dir\mainwindow.cpp.i

CMakeFiles/chess.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/mainwindow.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\mainwindow.cpp -o CMakeFiles\chess.dir\mainwindow.cpp.s

CMakeFiles/chess.dir/Core.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/Core.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/Core.cpp.obj: ../Core.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/chess.dir/Core.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\Core.cpp.obj -c C:\CLionProjects\chess\Core.cpp

CMakeFiles/chess.dir/Core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/Core.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\Core.cpp > CMakeFiles\chess.dir\Core.cpp.i

CMakeFiles/chess.dir/Core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/Core.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\Core.cpp -o CMakeFiles\chess.dir\Core.cpp.s

CMakeFiles/chess.dir/Chess.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/Chess.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/Chess.cpp.obj: ../Chess.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/chess.dir/Chess.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\Chess.cpp.obj -c C:\CLionProjects\chess\Chess.cpp

CMakeFiles/chess.dir/Chess.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/Chess.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\Chess.cpp > CMakeFiles\chess.dir\Chess.cpp.i

CMakeFiles/chess.dir/Chess.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/Chess.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\Chess.cpp -o CMakeFiles\chess.dir\Chess.cpp.s

CMakeFiles/chess.dir/BaseComponent.cpp.obj: CMakeFiles/chess.dir/flags.make
CMakeFiles/chess.dir/BaseComponent.cpp.obj: CMakeFiles/chess.dir/includes_CXX.rsp
CMakeFiles/chess.dir/BaseComponent.cpp.obj: ../BaseComponent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/chess.dir/BaseComponent.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\chess.dir\BaseComponent.cpp.obj -c C:\CLionProjects\chess\BaseComponent.cpp

CMakeFiles/chess.dir/BaseComponent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chess.dir/BaseComponent.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\CLionProjects\chess\BaseComponent.cpp > CMakeFiles\chess.dir\BaseComponent.cpp.i

CMakeFiles/chess.dir/BaseComponent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chess.dir/BaseComponent.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\CLionProjects\chess\BaseComponent.cpp -o CMakeFiles\chess.dir\BaseComponent.cpp.s

# Object files for target chess
chess_OBJECTS = \
"CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/chess.dir/main.cpp.obj" \
"CMakeFiles/chess.dir/mainwindow.cpp.obj" \
"CMakeFiles/chess.dir/Core.cpp.obj" \
"CMakeFiles/chess.dir/Chess.cpp.obj" \
"CMakeFiles/chess.dir/BaseComponent.cpp.obj"

# External object files for target chess
chess_EXTERNAL_OBJECTS =

chess.exe: CMakeFiles/chess.dir/chess_autogen/mocs_compilation.cpp.obj
chess.exe: CMakeFiles/chess.dir/main.cpp.obj
chess.exe: CMakeFiles/chess.dir/mainwindow.cpp.obj
chess.exe: CMakeFiles/chess.dir/Core.cpp.obj
chess.exe: CMakeFiles/chess.dir/Chess.cpp.obj
chess.exe: CMakeFiles/chess.dir/BaseComponent.cpp.obj
chess.exe: CMakeFiles/chess.dir/build.make
chess.exe: C:/Qt/Qt5.12.2/5.12.2/mingw73_64/lib/libQt5Widgetsd.a
chess.exe: C:/Qt/Qt5.12.2/5.12.2/mingw73_64/lib/libQt5Guid.a
chess.exe: C:/Qt/Qt5.12.2/5.12.2/mingw73_64/lib/libQt5Cored.a
chess.exe: CMakeFiles/chess.dir/linklibs.rsp
chess.exe: CMakeFiles/chess.dir/objects1.rsp
chess.exe: CMakeFiles/chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CLionProjects\chess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable chess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\chess.dir\link.txt --verbose=$(VERBOSE)
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E make_directory C:/CLionProjects/chess/cmake-build-debug/plugins/platforms/
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E copy C:/Qt/Qt5.12.2/5.12.2/mingw73_64/plugins/platforms/qwindowsd.dll C:/CLionProjects/chess/cmake-build-debug/plugins/platforms/
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E copy C:/Qt/Qt5.12.2/5.12.2/mingw73_64/bin/Qt5Cored.dll C:/CLionProjects/chess/cmake-build-debug
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E copy C:/Qt/Qt5.12.2/5.12.2/mingw73_64/bin/Qt5Guid.dll C:/CLionProjects/chess/cmake-build-debug
	"C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E copy C:/Qt/Qt5.12.2/5.12.2/mingw73_64/bin/Qt5Widgetsd.dll C:/CLionProjects/chess/cmake-build-debug

# Rule to build all files generated by this target.
CMakeFiles/chess.dir/build: chess.exe
.PHONY : CMakeFiles/chess.dir/build

CMakeFiles/chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\chess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/chess.dir/clean

CMakeFiles/chess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CLionProjects\chess C:\CLionProjects\chess C:\CLionProjects\chess\cmake-build-debug C:\CLionProjects\chess\cmake-build-debug C:\CLionProjects\chess\cmake-build-debug\CMakeFiles\chess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chess.dir/depend

