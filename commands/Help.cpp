#include "Help.h"
#include <iostream>
#include <memory>


using namespace std;
void Help::execute(string inputLine) {
    for (const auto& command : commandList) {
        cout << *command << endl;
    }
}

Help::Help(const std::vector<std::unique_ptr<ICommand>>& commandList) :
    commandList(commandList) {}

void Help::print(ostream& os) const {
    os << "help";
}

std::string Help::getCommandName() const {
    return "help";
}