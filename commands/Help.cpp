#include "Help.h"
#include <iostream>
using namespace std;
void Help::execute(string inputLine) {
    for (Icommand* command : commandList) {
        cout << *command << endl;
    }
}

Help::Help(const vector<Icommand*>& commandList) {
    this->commandList = commandList;
}

void Help::print(ostream& os) const {
    os << "help";
}