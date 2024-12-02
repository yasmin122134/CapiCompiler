#include <string>
#include "ICommand.h"

class IMenu {
public:
    
    // virtual method to get the next command
    virtual bool nextCommand();

    // Pure virtual method to display an error
    virtual void displayError(const std::string errorName);
};
