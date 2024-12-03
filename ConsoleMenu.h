#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "commands/ICommand.h"
#include "IMenu.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"

class ConsoleMenu : public IMenu {
private:
    std::vector<ICommand*> commands;
    IUserDAL* userDAL;
    IMovieDAL* movieDAL;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    ConsoleMenu(std::vector<ICommand*> cmdList, IUserDAL* userDal, IMovieDAL* movieDal, 
                std::istream& input, std::ostream& output);
    bool nextCommand() override;
    void displayError(const std::string& errorName) override;
};

#endif
