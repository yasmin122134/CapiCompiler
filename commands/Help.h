#ifndef HELP_H
#define HELP_H
#include "ICommand.h"
#include <vector>
using namespace std;
class Help : public ICommand {
private:
    vector<ICommand*> commandList;
public:
    Help(const vector<ICommand*>& commandList);
    void execute(string inputLine) override;
    void print(ostream& os) const override;
    std::string getCommandName() const override;
};

#endif