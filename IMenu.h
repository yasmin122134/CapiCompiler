#ifndef ICOMMANDINTERFACE_H
#define ICOMMANDINTERFACE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class ICommandInterface {
public:
    
    // virtual method to get the next command
    virtual bool nextCommand();

    // Pure virtual method to display an error
    virtual void displayError(const std::string errorName);
};
#endif