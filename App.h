#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "ConsoleMenu.h"

class App {
private:
    std::vector<std::unique_ptr<ICommand>> commands; // Command list
    std::unique_ptr<IUserDAL> userDAL;               // User data access layer
    std::unique_ptr<IMovieDAL> movieDAL;             // Movie data access layer
    std::istream& inputStream;                       // Input stream (e.g., std::cin)
    std::ostream& outputStream;                      // Output stream (e.g., std::cout)

public:
    // Constructor
    App(std::vector<std::unique_ptr<ICommand>> cmdList,
        std::unique_ptr<IUserDAL> userDal,
        std::unique_ptr<IMovieDAL> movieDal,
        std::istream& input,
        std::ostream& output);

    // Run function
    void run();
};
