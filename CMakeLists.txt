cmake_minimum_required(VERSION 3.10)

# Project name
project(CapyNetflix)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include FetchContent for GTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# Prevent overriding compiler/linker settings for Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Set source files
set(SOURCE_FILES
    Movie.cpp
    User.cpp
    MovieDALFile.cpp
    UserDALFile.cpp
    commands/Recommend.cpp
    IMovieDAL.h
    IUserDAL.h
    commands/Icommand.h
)

# Set test files
set(TEST_FILES
    tests/recommend_test.cpp
)

# Add test executable
add_executable(UserTests ${SOURCE_FILES} ${TEST_FILES})

# Link GTest to the test executable
target_link_libraries(UserTests gtest_main)

# Enable testing
enable_testing()
add_test(NAME AllTests COMMAND UserTests)