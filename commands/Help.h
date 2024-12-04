#ifndef HELP_H
#define HELP_H
#include "ICommand.h"
#include <vector>
using namespace std;

class Help : public ICommand {
private:
    vector<ICommand*> commandList; // Use raw pointers instead of unique_ptr

public:
    Help(const std::vector<ICommand*>& commandList); // Constructor accepting raw pointers
    void execute(string inputLine) override;
    void print(ostream& os) const override;
    std::string getCommandName() const override;
    Help();
    void setCommandList(std::vector<ICommand*>& commandList);
};

#endif
