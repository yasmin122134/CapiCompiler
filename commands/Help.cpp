#include "Help.h"
#include <iostream>
using namespace std;
void Help::execute(string inputLine) {
    for (ICommand* command : commandList) {
        cout << *command << endl;
    }
}

Help::Help(const vector<ICommand*>& commandList) {
    this->commandList = commandList;
}

void Help::print(ostream& os) const {
    os << "help";
}

std::string Help::getCommandName() const {
    return "help";
}