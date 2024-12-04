#include <iostream>
#include <vector>
#include "commands/Add.h"
#include "commands/Help.h"
#include "commands/Recommend.h"
#include "App.h"
#include "DataAccessLayer.h"
int main() {

    // Create instances of the DALs
    DataAccessLayer dal = DataAccessLayer();

    // Create a vector of raw pointers to commands
    std::vector<ICommand*> commands;
    commands.push_back(new Add(dal));
    commands.push_back(new Help(commands));
    commands.push_back(new Recommend(dal));

    // Pass raw pointers to the App class
    App app(commands, std::cin, std::cout);
    app.run();

    // Clean up allocated memory
    for (auto cmd : commands) {
        delete cmd;
    }
//    delete dal;

    return 0;
}
