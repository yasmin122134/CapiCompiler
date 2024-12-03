#include "ICommand.h"

void execute(std::string inputLine);
void print(std::ostream& os); // New virtual function
std::string getCommandName();
std::ostream& operator<<(std::ostream& os, const ICommand& cmd) {
        cmd.print(os); 
        return os;
    }
