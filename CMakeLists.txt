cmake_minimum_required(VERSION 3.24)
project(mitkademTarg1)

set(CMAKE_CXX_STANDARD 17)


# Include FetchContent for GTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Prevent overriding compiler/linker settings for Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Set source files
set(SOURCE_FILES
        Movie.cpp
        User.cpp
        Main.cpp
        IMenu.cpp
        ConsoleMenu.cpp
        App.cpp
        commands/ICommand.cpp
        commands/Add.cpp
        commands/Recommend.cpp
        commands/Help.cpp
        DataAccessLayer.cpp
        )

## Set test files
 #set(TEST_FILES
##        tests/DALTests.cpp
##        DataAccessLayer.cpp
##        User.cpp
##        Movie.cpp
#          test/End_to_End.cpp
 #       )


# Add main executable
#add_executable(MainApp ${SOURCE_FILES})

# Add test executable
#add_executable(UserTests ${TEST_FILES})

# Link GTest to the test executable
#target_link_libraries(UserTests gtest_main)

# Enable testing
#enable_testing()
#add_test(NAME AllTests COMMAND UserTests)