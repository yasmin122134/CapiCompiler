#ifndef ICOMMANDINTERFACE_H
#define ICOMMANDINTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class IMenu {

public:

    // virtual ~IMenu() = default;

    virtual bool nextCommand() = 0;

    virtual void displayError(const std::string errorName) = 0;

};

#endif