cmake_minimum_required(VERSION 3.24)
project(mitkademTarg1)

set(CMAKE_CXX_STANDARD 17)

add_executable(mitkademTarg1
        Movie.cpp
        User.cpp
        MovieDALFile.cpp
        UserDALFile.cpp
        Main.cpp
        IMenu.cpp
        ConsoleMenu.cpp
        App.cpp
        commands/ICommand.cpp
        commands/Add.cpp
        commands/Recommend.cpp
        commands/Help.cpp DataAccessLayer.cpp)
