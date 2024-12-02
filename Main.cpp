#include <iostream>
#include <memory>
#include <vector>
#include "commands/ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "commands/Help.h"
#include "commands/Recommend.h"
#include "commands/Add.h"
#include "UserDALFile.h"
#include "MovieDALFile.h"
#include "App.h"

class Main {
    static int main() {
        // Initialize UserDAL and MovieDAL using polymorphism
        std::unique_ptr<IUserDAL> userDAL = std::make_unique<UserDALFile>();
        std::unique_ptr<IMovieDAL> movieDAL = std::make_unique<MovieDALFile>();

        // Initialize commands using polymorphism
        std::vector<std::unique_ptr<ICommand>> commands;
        commands.push_back(std::make_unique<Help>(commands));
        commands.push_back(std::make_unique<Recommend>(movieDAL, userDAL));
        commands.push_back(std::make_unique<Add>(userDAL));

        // Initialize the App with standard input/output streams
        App app(
            std::move(commands),
            std::move(userDAL),
            std::move(movieDAL),
            std::cin,
            std::cout
        );

        // Run the application
        app.run();

        return 0;
    }
};
