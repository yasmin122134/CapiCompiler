#include "App.h"

App::App(std::vector<ICommand*> cmdList, IUserDAL* userDal, IMovieDAL* movieDal, 
         std::istream& input, std::ostream& output)
    : commands(cmdList), userDAL(userDal), movieDAL(movieDal), 
      inputStream(input), outputStream(output) {}

void App::run() {
    ConsoleMenu menu(commands, userDAL, movieDAL, inputStream, outputStream);

    while (true) {
        try {
            bool continueExecution = menu.nextCommand();
            if (!continueExecution) {
                continue; // Exit loop if nextCommand signals termination
            }
        } catch (const std::exception& e) {
        } catch (...) {
        }
    }
}
