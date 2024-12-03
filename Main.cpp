#include <iostream>
#include <vector>
#include "commands/Add.h"
#include "commands/Help.h"
#include "commands/Recommend.h"
#include "UserDALFile.h"
#include "MovieDALFile.h"
#include "App.h"

int main() {
    // Allocate raw pointers
    IUserDAL* userDAL = new UserDALFile();
    IMovieDAL* movieDAL = new MovieDALFile();

    // Create a vector of raw pointers to commands
    std::vector<ICommand*> commands;
    commands.push_back(new Add(userDAL,movieDAL));
    commands.push_back(new Help(commands));
    commands.push_back(new Recommend(movieDAL, userDAL));

    // Pass raw pointers to the App class
    App app(commands, userDAL, movieDAL, std::cin, std::cout);
    app.run();

    // Clean up allocated memory
    for (auto cmd : commands) {
        delete cmd;
    }
    delete userDAL;
    delete movieDAL;

    return 0;
}
