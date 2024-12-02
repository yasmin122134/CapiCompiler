#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
#include <iostream>

class ICommand {
public:
    virtual void execute(std::string inputLine) = 0;
    virtual void print(std::ostream& os) const = 0;
};

#endif // ICOMMAND_H
