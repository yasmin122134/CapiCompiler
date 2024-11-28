#include "Help.h"
#include <iostream>
using namespace std;
void Help::execute() {
    for (Icommand* command : commandList) {
        cout << *command << endl;
    }
}

Help::Help(const vector<Icommand*>& commandList) {
    this->commandList = commandList;
}

ostream& operator<<(ostream& os, const Help& help) {
    return os << "help";
}
