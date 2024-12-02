#include <iostream>
#include <string>
#include "ICommand.h"

// Assuming Command is a simple alias for std::string. Modify as needed.
using Command = std::string;

class ConsoleMenu : public IMenu {
public:
    // Implement the nextCommand method
    Command nextCommand(std::istream& stream) override {
         
       
        return command;
    }

    // Implement the displayError method
    void displayError(const std::string errorName) override {
        std::cerr << "Error: " << errorName << std::endl;
    }
};
