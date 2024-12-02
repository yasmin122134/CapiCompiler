#include "ICommand.h"

class ICommand {
public:
    virtual void execute(std::string inputLine) = 0;
    virtual void print(std::ostream& os) const = 0; // New virtual function
    virtual std::string getCommandName() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const ICommand& cmd) {
        cmd.print(os); 
        return os;
    }
};
