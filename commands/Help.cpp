#include "Help.h"
#include <iostream>

using namespace std;

// Execute the command by printing the list of commands
void Help::execute(string inputLine) {
    for (const auto& command : commandList) {
        cout << *command << endl;
    }
}

// Constructor to initialize the command list with raw pointers
Help::Help(const std::vector<ICommand*>& commandList) :
    commandList(commandList) {}

// Print command usage
void Help::print(ostream& os) const {
    os << "help";
}

// Get the name of the command
std::string Help::getCommandName() const {
    return "help";
}
