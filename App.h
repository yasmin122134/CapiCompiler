#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include "commands/ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "ConsoleMenu.h"

class App {
private:
    std::vector<ICommand*> commands;
    IUserDAL* userDAL;
    IMovieDAL* movieDAL;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    App(std::vector<ICommand*> cmdList, IUserDAL* userDal, IMovieDAL* movieDal, 
        std::istream& input, std::ostream& output);
    void run();
};

#endif
