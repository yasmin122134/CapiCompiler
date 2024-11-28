#ifndef HELP_H
#define HELP_H
#include "Icommand.h"
#include <vector>
using namespace std;
class Help : public Icommand {
private:
    vector<Icommand*> commandList;
public:
    Help(const vector<Icommand*>& commandList);
    void execute() override;
    ostream& operator<<(std::ostream& os);
};

#endif
