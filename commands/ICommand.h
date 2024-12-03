#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <iostream>

class ICommand {
public:
    virtual void execute(std::string inputLine) = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual std::string getCommandName() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const ICommand& cmd);
};

#endif //ICOMMAND_H
