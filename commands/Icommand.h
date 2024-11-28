#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <iostream>

class Icommand {
public:
    virtual void execute() = 0;
    friend std::ostream& operator<<(std::ostream& os, const Icommand& cmd);
};

#endif
