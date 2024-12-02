#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include "commands/ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "IMenu.h"

class ConsoleMenu : public IMenu {
private:
    std::vector<std::unique_ptr<ICommand>> commands;  // List of commands
    std::unique_ptr<IUserDAL> userDAL;                // User data access layer
    std::unique_ptr<IMovieDAL> movieDAL;              // Movie data access layer
    std::istream& inputStream;                        // Input stream (e.g., std::cin)
    std::ostream& outputStream;                       // Output stream (e.g., std::cout)

public:
    // Constructor
    ConsoleMenu(
        std::vector<std::unique_ptr<ICommand>> cmdList,
        std::unique_ptr<IUserDAL> userDal,
        std::unique_ptr<IMovieDAL> movieDal,
        std::istream& input,
        std::ostream& output);

    // ~ConsoleMenu() noexcept override = default;

    // Method to process the next command
    bool nextCommand() override;

    // Method to display errors
    void displayError(const std::string errorName) override;

// private:
//     std::vector<std::unique_ptr<ICommand>> commands;
//     std::unique_ptr<IUserDAL> userDAL;
//     std::unique_ptr<IMovieDAL> movieDAL;
//     std::istream& inputStream;
//     std::ostream& outputStream;
};
