# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/omer/CapiCompiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/omer/CapiCompiler

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running tests..."
	/opt/homebrew/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/opt/homebrew/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Install the project..."
	/opt/homebrew/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing only the local directory..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Installing the project stripped..."
	/opt/homebrew/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/omer/CapiCompiler/CMakeFiles /Users/omer/CapiCompiler//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/omer/CapiCompiler/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MainApp

# Build rule for target.
MainApp: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MainApp
.PHONY : MainApp

# fast build rule for target.
MainApp/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/build
.PHONY : MainApp/fast

#=============================================================================
# Target rules for targets named UserTests

# Build rule for target.
UserTests: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 UserTests
.PHONY : UserTests

# fast build rule for target.
UserTests/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/build
.PHONY : UserTests/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

App.o: App.cpp.o
.PHONY : App.o

# target to build an object file
App.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/App.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/App.cpp.o
.PHONY : App.cpp.o

App.i: App.cpp.i
.PHONY : App.i

# target to preprocess a source file
App.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/App.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/App.cpp.i
.PHONY : App.cpp.i

App.s: App.cpp.s
.PHONY : App.s

# target to generate assembly for a file
App.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/App.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/App.cpp.s
.PHONY : App.cpp.s

ConsoleMenu.o: ConsoleMenu.cpp.o
.PHONY : ConsoleMenu.o

# target to build an object file
ConsoleMenu.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/ConsoleMenu.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/ConsoleMenu.cpp.o
.PHONY : ConsoleMenu.cpp.o

ConsoleMenu.i: ConsoleMenu.cpp.i
.PHONY : ConsoleMenu.i

# target to preprocess a source file
ConsoleMenu.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/ConsoleMenu.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/ConsoleMenu.cpp.i
.PHONY : ConsoleMenu.cpp.i

ConsoleMenu.s: ConsoleMenu.cpp.s
.PHONY : ConsoleMenu.s

# target to generate assembly for a file
ConsoleMenu.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/ConsoleMenu.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/ConsoleMenu.cpp.s
.PHONY : ConsoleMenu.cpp.s

IMenu.o: IMenu.cpp.o
.PHONY : IMenu.o

# target to build an object file
IMenu.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/IMenu.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/IMenu.cpp.o
.PHONY : IMenu.cpp.o

IMenu.i: IMenu.cpp.i
.PHONY : IMenu.i

# target to preprocess a source file
IMenu.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/IMenu.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/IMenu.cpp.i
.PHONY : IMenu.cpp.i

IMenu.s: IMenu.cpp.s
.PHONY : IMenu.s

# target to generate assembly for a file
IMenu.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/IMenu.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/IMenu.cpp.s
.PHONY : IMenu.cpp.s

Main.o: Main.cpp.o
.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Main.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i
.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Main.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s
.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Main.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Main.cpp.s
.PHONY : Main.cpp.s

Movie.o: Movie.cpp.o
.PHONY : Movie.o

# target to build an object file
Movie.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Movie.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Movie.cpp.o
.PHONY : Movie.cpp.o

Movie.i: Movie.cpp.i
.PHONY : Movie.i

# target to preprocess a source file
Movie.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Movie.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Movie.cpp.i
.PHONY : Movie.cpp.i

Movie.s: Movie.cpp.s
.PHONY : Movie.s

# target to generate assembly for a file
Movie.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/Movie.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/Movie.cpp.s
.PHONY : Movie.cpp.s

MovieDALFile.o: MovieDALFile.cpp.o
.PHONY : MovieDALFile.o

# target to build an object file
MovieDALFile.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/MovieDALFile.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/MovieDALFile.cpp.o
.PHONY : MovieDALFile.cpp.o

MovieDALFile.i: MovieDALFile.cpp.i
.PHONY : MovieDALFile.i

# target to preprocess a source file
MovieDALFile.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/MovieDALFile.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/MovieDALFile.cpp.i
.PHONY : MovieDALFile.cpp.i

MovieDALFile.s: MovieDALFile.cpp.s
.PHONY : MovieDALFile.s

# target to generate assembly for a file
MovieDALFile.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/MovieDALFile.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/MovieDALFile.cpp.s
.PHONY : MovieDALFile.cpp.s

User.o: User.cpp.o
.PHONY : User.o

# target to build an object file
User.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/User.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/User.cpp.o
.PHONY : User.cpp.o

User.i: User.cpp.i
.PHONY : User.i

# target to preprocess a source file
User.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/User.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/User.cpp.i
.PHONY : User.cpp.i

User.s: User.cpp.s
.PHONY : User.s

# target to generate assembly for a file
User.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/User.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/User.cpp.s
.PHONY : User.cpp.s

UserDALFile.o: UserDALFile.cpp.o
.PHONY : UserDALFile.o

# target to build an object file
UserDALFile.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/UserDALFile.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/UserDALFile.cpp.o
.PHONY : UserDALFile.cpp.o

UserDALFile.i: UserDALFile.cpp.i
.PHONY : UserDALFile.i

# target to preprocess a source file
UserDALFile.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/UserDALFile.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/UserDALFile.cpp.i
.PHONY : UserDALFile.cpp.i

UserDALFile.s: UserDALFile.cpp.s
.PHONY : UserDALFile.s

# target to generate assembly for a file
UserDALFile.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/UserDALFile.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/UserDALFile.cpp.s
.PHONY : UserDALFile.cpp.s

commands/Add.o: commands/Add.cpp.o
.PHONY : commands/Add.o

# target to build an object file
commands/Add.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Add.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Add.cpp.o
.PHONY : commands/Add.cpp.o

commands/Add.i: commands/Add.cpp.i
.PHONY : commands/Add.i

# target to preprocess a source file
commands/Add.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Add.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Add.cpp.i
.PHONY : commands/Add.cpp.i

commands/Add.s: commands/Add.cpp.s
.PHONY : commands/Add.s

# target to generate assembly for a file
commands/Add.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Add.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Add.cpp.s
.PHONY : commands/Add.cpp.s

commands/Help.o: commands/Help.cpp.o
.PHONY : commands/Help.o

# target to build an object file
commands/Help.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Help.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Help.cpp.o
.PHONY : commands/Help.cpp.o

commands/Help.i: commands/Help.cpp.i
.PHONY : commands/Help.i

# target to preprocess a source file
commands/Help.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Help.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Help.cpp.i
.PHONY : commands/Help.cpp.i

commands/Help.s: commands/Help.cpp.s
.PHONY : commands/Help.s

# target to generate assembly for a file
commands/Help.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Help.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Help.cpp.s
.PHONY : commands/Help.cpp.s

commands/ICommand.o: commands/ICommand.cpp.o
.PHONY : commands/ICommand.o

# target to build an object file
commands/ICommand.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/ICommand.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/ICommand.cpp.o
.PHONY : commands/ICommand.cpp.o

commands/ICommand.i: commands/ICommand.cpp.i
.PHONY : commands/ICommand.i

# target to preprocess a source file
commands/ICommand.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/ICommand.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/ICommand.cpp.i
.PHONY : commands/ICommand.cpp.i

commands/ICommand.s: commands/ICommand.cpp.s
.PHONY : commands/ICommand.s

# target to generate assembly for a file
commands/ICommand.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/ICommand.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/ICommand.cpp.s
.PHONY : commands/ICommand.cpp.s

commands/Recommend.o: commands/Recommend.cpp.o
.PHONY : commands/Recommend.o

# target to build an object file
commands/Recommend.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Recommend.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Recommend.cpp.o
.PHONY : commands/Recommend.cpp.o

commands/Recommend.i: commands/Recommend.cpp.i
.PHONY : commands/Recommend.i

# target to preprocess a source file
commands/Recommend.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Recommend.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Recommend.cpp.i
.PHONY : commands/Recommend.cpp.i

commands/Recommend.s: commands/Recommend.cpp.s
.PHONY : commands/Recommend.s

# target to generate assembly for a file
commands/Recommend.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MainApp.dir/build.make CMakeFiles/MainApp.dir/commands/Recommend.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/commands/Recommend.cpp.s
.PHONY : commands/Recommend.cpp.s

tests/MovieDALFileTest.o: tests/MovieDALFileTest.cpp.o
.PHONY : tests/MovieDALFileTest.o

# target to build an object file
tests/MovieDALFileTest.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/MovieDALFileTest.cpp.o
.PHONY : tests/MovieDALFileTest.cpp.o

tests/MovieDALFileTest.i: tests/MovieDALFileTest.cpp.i
.PHONY : tests/MovieDALFileTest.i

# target to preprocess a source file
tests/MovieDALFileTest.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/MovieDALFileTest.cpp.i
.PHONY : tests/MovieDALFileTest.cpp.i

tests/MovieDALFileTest.s: tests/MovieDALFileTest.cpp.s
.PHONY : tests/MovieDALFileTest.s

# target to generate assembly for a file
tests/MovieDALFileTest.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/MovieDALFileTest.cpp.s
.PHONY : tests/MovieDALFileTest.cpp.s

tests/UserDALFileTest.o: tests/UserDALFileTest.cpp.o
.PHONY : tests/UserDALFileTest.o

# target to build an object file
tests/UserDALFileTest.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/UserDALFileTest.cpp.o
.PHONY : tests/UserDALFileTest.cpp.o

tests/UserDALFileTest.i: tests/UserDALFileTest.cpp.i
.PHONY : tests/UserDALFileTest.i

# target to preprocess a source file
tests/UserDALFileTest.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/UserDALFileTest.cpp.i
.PHONY : tests/UserDALFileTest.cpp.i

tests/UserDALFileTest.s: tests/UserDALFileTest.cpp.s
.PHONY : tests/UserDALFileTest.s

# target to generate assembly for a file
tests/UserDALFileTest.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/UserTests.dir/build.make CMakeFiles/UserTests.dir/tests/UserDALFileTest.cpp.s
.PHONY : tests/UserDALFileTest.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... MainApp"
	@echo "... UserTests"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... App.o"
	@echo "... App.i"
	@echo "... App.s"
	@echo "... ConsoleMenu.o"
	@echo "... ConsoleMenu.i"
	@echo "... ConsoleMenu.s"
	@echo "... IMenu.o"
	@echo "... IMenu.i"
	@echo "... IMenu.s"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... Movie.o"
	@echo "... Movie.i"
	@echo "... Movie.s"
	@echo "... MovieDALFile.o"
	@echo "... MovieDALFile.i"
	@echo "... MovieDALFile.s"
	@echo "... User.o"
	@echo "... User.i"
	@echo "... User.s"
	@echo "... UserDALFile.o"
	@echo "... UserDALFile.i"
	@echo "... UserDALFile.s"
	@echo "... commands/Add.o"
	@echo "... commands/Add.i"
	@echo "... commands/Add.s"
	@echo "... commands/Help.o"
	@echo "... commands/Help.i"
	@echo "... commands/Help.s"
	@echo "... commands/ICommand.o"
	@echo "... commands/ICommand.i"
	@echo "... commands/ICommand.s"
	@echo "... commands/Recommend.o"
	@echo "... commands/Recommend.i"
	@echo "... commands/Recommend.s"
	@echo "... tests/MovieDALFileTest.o"
	@echo "... tests/MovieDALFileTest.i"
	@echo "... tests/MovieDALFileTest.s"
	@echo "... tests/UserDALFileTest.o"
	@echo "... tests/UserDALFileTest.i"
	@echo "... tests/UserDALFileTest.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

