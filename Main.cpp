#include <iostream>
#include <memory>
#include <vector>
#include "ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "Help.h"
#include "Recommend.h"
#include "AddMovie.h"
#include "UserDAL.h"
#include "MovieDAL.h"
#include "App.h"

class Main {
    static int main() {
        // Initialize UserDAL and MovieDAL using polymorphism
        std::unique_ptr<IUserDAL> userDAL = std::make_unique<UserDAL>();
        std::unique_ptr<IMovieDAL> movieDAL = std::make_unique<MovieDAL>();

        // Initialize commands using polymorphism
        std::vector<std::unique_ptr<ICommand>> commands;
        commands.push_back(std::make_unique<Help>());
        commands.push_back(std::make_unique<Recommend>());
        commands.push_back(std::make_unique<AddMovie>());

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
