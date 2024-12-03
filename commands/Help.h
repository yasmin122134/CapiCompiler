#ifndef HELP_H
#define HELP_H
#include "ICommand.h"
#include <vector>
using namespace std;
class Help : public ICommand {
private:
    vector<unique_ptr<ICommand>> commandList;
public:
    Help(const std::vector<std::unique_ptr<ICommand>>& commandList);
    void execute(string inputLine) override;
    void print(ostream& os) const override;
    std::string getCommandName() const override;
};

#endif