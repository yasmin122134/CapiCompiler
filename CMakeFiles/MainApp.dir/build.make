# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omer/CapiCompiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omer/CapiCompiler

# Include any dependencies generated for this target.
include CMakeFiles/MainApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MainApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MainApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MainApp.dir/flags.make

CMakeFiles/MainApp.dir/Movie.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/Movie.cpp.o: Movie.cpp
CMakeFiles/MainApp.dir/Movie.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MainApp.dir/Movie.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/Movie.cpp.o -MF CMakeFiles/MainApp.dir/Movie.cpp.o.d -o CMakeFiles/MainApp.dir/Movie.cpp.o -c /Users/omer/CapiCompiler/Movie.cpp

CMakeFiles/MainApp.dir/Movie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/Movie.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/Movie.cpp > CMakeFiles/MainApp.dir/Movie.cpp.i

CMakeFiles/MainApp.dir/Movie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/Movie.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/Movie.cpp -o CMakeFiles/MainApp.dir/Movie.cpp.s

CMakeFiles/MainApp.dir/User.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/User.cpp.o: User.cpp
CMakeFiles/MainApp.dir/User.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MainApp.dir/User.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/User.cpp.o -MF CMakeFiles/MainApp.dir/User.cpp.o.d -o CMakeFiles/MainApp.dir/User.cpp.o -c /Users/omer/CapiCompiler/User.cpp

CMakeFiles/MainApp.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/User.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/User.cpp > CMakeFiles/MainApp.dir/User.cpp.i

CMakeFiles/MainApp.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/User.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/User.cpp -o CMakeFiles/MainApp.dir/User.cpp.s

CMakeFiles/MainApp.dir/Main.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/Main.cpp.o: Main.cpp
CMakeFiles/MainApp.dir/Main.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MainApp.dir/Main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/Main.cpp.o -MF CMakeFiles/MainApp.dir/Main.cpp.o.d -o CMakeFiles/MainApp.dir/Main.cpp.o -c /Users/omer/CapiCompiler/Main.cpp

CMakeFiles/MainApp.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/Main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/Main.cpp > CMakeFiles/MainApp.dir/Main.cpp.i

CMakeFiles/MainApp.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/Main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/Main.cpp -o CMakeFiles/MainApp.dir/Main.cpp.s

CMakeFiles/MainApp.dir/IMenu.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/IMenu.cpp.o: IMenu.cpp
CMakeFiles/MainApp.dir/IMenu.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MainApp.dir/IMenu.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/IMenu.cpp.o -MF CMakeFiles/MainApp.dir/IMenu.cpp.o.d -o CMakeFiles/MainApp.dir/IMenu.cpp.o -c /Users/omer/CapiCompiler/IMenu.cpp

CMakeFiles/MainApp.dir/IMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/IMenu.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/IMenu.cpp > CMakeFiles/MainApp.dir/IMenu.cpp.i

CMakeFiles/MainApp.dir/IMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/IMenu.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/IMenu.cpp -o CMakeFiles/MainApp.dir/IMenu.cpp.s

CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o: ConsoleMenu.cpp
CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o -MF CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o.d -o CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o -c /Users/omer/CapiCompiler/ConsoleMenu.cpp

CMakeFiles/MainApp.dir/ConsoleMenu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/ConsoleMenu.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/ConsoleMenu.cpp > CMakeFiles/MainApp.dir/ConsoleMenu.cpp.i

CMakeFiles/MainApp.dir/ConsoleMenu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/ConsoleMenu.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/ConsoleMenu.cpp -o CMakeFiles/MainApp.dir/ConsoleMenu.cpp.s

CMakeFiles/MainApp.dir/App.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/App.cpp.o: App.cpp
CMakeFiles/MainApp.dir/App.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/MainApp.dir/App.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/App.cpp.o -MF CMakeFiles/MainApp.dir/App.cpp.o.d -o CMakeFiles/MainApp.dir/App.cpp.o -c /Users/omer/CapiCompiler/App.cpp

CMakeFiles/MainApp.dir/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/App.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/App.cpp > CMakeFiles/MainApp.dir/App.cpp.i

CMakeFiles/MainApp.dir/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/App.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/App.cpp -o CMakeFiles/MainApp.dir/App.cpp.s

CMakeFiles/MainApp.dir/commands/ICommand.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/commands/ICommand.cpp.o: commands/ICommand.cpp
CMakeFiles/MainApp.dir/commands/ICommand.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/MainApp.dir/commands/ICommand.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/commands/ICommand.cpp.o -MF CMakeFiles/MainApp.dir/commands/ICommand.cpp.o.d -o CMakeFiles/MainApp.dir/commands/ICommand.cpp.o -c /Users/omer/CapiCompiler/commands/ICommand.cpp

CMakeFiles/MainApp.dir/commands/ICommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/commands/ICommand.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/commands/ICommand.cpp > CMakeFiles/MainApp.dir/commands/ICommand.cpp.i

CMakeFiles/MainApp.dir/commands/ICommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/commands/ICommand.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/commands/ICommand.cpp -o CMakeFiles/MainApp.dir/commands/ICommand.cpp.s

CMakeFiles/MainApp.dir/commands/Add.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/commands/Add.cpp.o: commands/Add.cpp
CMakeFiles/MainApp.dir/commands/Add.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MainApp.dir/commands/Add.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/commands/Add.cpp.o -MF CMakeFiles/MainApp.dir/commands/Add.cpp.o.d -o CMakeFiles/MainApp.dir/commands/Add.cpp.o -c /Users/omer/CapiCompiler/commands/Add.cpp

CMakeFiles/MainApp.dir/commands/Add.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/commands/Add.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/commands/Add.cpp > CMakeFiles/MainApp.dir/commands/Add.cpp.i

CMakeFiles/MainApp.dir/commands/Add.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/commands/Add.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/commands/Add.cpp -o CMakeFiles/MainApp.dir/commands/Add.cpp.s

CMakeFiles/MainApp.dir/commands/Recommend.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/commands/Recommend.cpp.o: commands/Recommend.cpp
CMakeFiles/MainApp.dir/commands/Recommend.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MainApp.dir/commands/Recommend.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/commands/Recommend.cpp.o -MF CMakeFiles/MainApp.dir/commands/Recommend.cpp.o.d -o CMakeFiles/MainApp.dir/commands/Recommend.cpp.o -c /Users/omer/CapiCompiler/commands/Recommend.cpp

CMakeFiles/MainApp.dir/commands/Recommend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/commands/Recommend.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/commands/Recommend.cpp > CMakeFiles/MainApp.dir/commands/Recommend.cpp.i

CMakeFiles/MainApp.dir/commands/Recommend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/commands/Recommend.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/commands/Recommend.cpp -o CMakeFiles/MainApp.dir/commands/Recommend.cpp.s

CMakeFiles/MainApp.dir/commands/Help.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/commands/Help.cpp.o: commands/Help.cpp
CMakeFiles/MainApp.dir/commands/Help.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/MainApp.dir/commands/Help.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/commands/Help.cpp.o -MF CMakeFiles/MainApp.dir/commands/Help.cpp.o.d -o CMakeFiles/MainApp.dir/commands/Help.cpp.o -c /Users/omer/CapiCompiler/commands/Help.cpp

CMakeFiles/MainApp.dir/commands/Help.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/commands/Help.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/commands/Help.cpp > CMakeFiles/MainApp.dir/commands/Help.cpp.i

CMakeFiles/MainApp.dir/commands/Help.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/commands/Help.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/commands/Help.cpp -o CMakeFiles/MainApp.dir/commands/Help.cpp.s

CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o: CMakeFiles/MainApp.dir/flags.make
CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o: DataAccessLayerFile.cpp
CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o: CMakeFiles/MainApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o -MF CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o.d -o CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o -c /Users/omer/CapiCompiler/DataAccessLayerFile.cpp

CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/omer/CapiCompiler/DataAccessLayerFile.cpp > CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.i

CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/omer/CapiCompiler/DataAccessLayerFile.cpp -o CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.s

# Object files for target MainApp
MainApp_OBJECTS = \
"CMakeFiles/MainApp.dir/Movie.cpp.o" \
"CMakeFiles/MainApp.dir/User.cpp.o" \
"CMakeFiles/MainApp.dir/Main.cpp.o" \
"CMakeFiles/MainApp.dir/IMenu.cpp.o" \
"CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o" \
"CMakeFiles/MainApp.dir/App.cpp.o" \
"CMakeFiles/MainApp.dir/commands/ICommand.cpp.o" \
"CMakeFiles/MainApp.dir/commands/Add.cpp.o" \
"CMakeFiles/MainApp.dir/commands/Recommend.cpp.o" \
"CMakeFiles/MainApp.dir/commands/Help.cpp.o" \
"CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o"

# External object files for target MainApp
MainApp_EXTERNAL_OBJECTS =

MainApp: CMakeFiles/MainApp.dir/Movie.cpp.o
MainApp: CMakeFiles/MainApp.dir/User.cpp.o
MainApp: CMakeFiles/MainApp.dir/Main.cpp.o
MainApp: CMakeFiles/MainApp.dir/IMenu.cpp.o
MainApp: CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o
MainApp: CMakeFiles/MainApp.dir/App.cpp.o
MainApp: CMakeFiles/MainApp.dir/commands/ICommand.cpp.o
MainApp: CMakeFiles/MainApp.dir/commands/Add.cpp.o
MainApp: CMakeFiles/MainApp.dir/commands/Recommend.cpp.o
MainApp: CMakeFiles/MainApp.dir/commands/Help.cpp.o
MainApp: CMakeFiles/MainApp.dir/DataAccessLayerFile.cpp.o
MainApp: CMakeFiles/MainApp.dir/build.make
MainApp: CMakeFiles/MainApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/omer/CapiCompiler/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable MainApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MainApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MainApp.dir/build: MainApp
.PHONY : CMakeFiles/MainApp.dir/build

CMakeFiles/MainApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MainApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MainApp.dir/clean

CMakeFiles/MainApp.dir/depend:
	cd /Users/omer/CapiCompiler && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/omer/CapiCompiler /Users/omer/CapiCompiler /Users/omer/CapiCompiler /Users/omer/CapiCompiler /Users/omer/CapiCompiler/CMakeFiles/MainApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MainApp.dir/depend

