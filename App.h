#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include "commands/ICommand.h"
#include "ConsoleMenu.h"
#include "DataAccessLayer.h"

using namespace std;

class App {
private:
    std::vector<ICommand*> commands;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    App(vector<ICommand*> cmdList, istream& input, ostream& output);
    void run();
};

#endif
