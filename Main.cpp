#include <iostream>
#include <vector>
#include "commands/Add.h"
#include "commands/Help.h"
#include "commands/Recommend.h"
#include "App.h"
#include "DataAccessLayerFile.h"
int main() {

//    cout << "Welcome to the Movie Recommender!" << endl;
    // Create instances of the DALs
    DataAccessLayerFile dal = DataAccessLayerFile();

    // Create a vector of raw pointers to commands
    std::vector<ICommand*> commands;
    Help* help = new Help();
    commands.push_back(new Add(&dal));
    commands.push_back(new Recommend(&dal));
    commands.push_back(help);
    help->setCommandList(commands);

    // Pass raw pointers to the App class
//    cout << "Commands available: add, recommend, help" << endl;
cout.flush();
    App app(commands, std::cin, std::cout);
    app.run();

    // Clean up allocated memory
    for (auto cmd : commands) {
        delete cmd;
    }
//    delete dal;

    return 0;
}
