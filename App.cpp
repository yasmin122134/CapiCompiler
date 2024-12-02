#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include "commands/ICommand.h"
#include "commands/Add.h"
#include "commands/Help.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "ConsoleMenu.h"
#include "UserDALFile.h"
#include "MovieDALFile.h"
#include "commands/Recommend.h"


// App Class
class App {
private:
    std::vector<std::unique_ptr<ICommand>> commands;
    std::unique_ptr<IUserDAL> userDAL;
    std::unique_ptr<IMovieDAL> movieDAL;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    // Constructor
    App(std::vector<std::unique_ptr<ICommand>> cmdList,
        std::unique_ptr<IUserDAL> userDal,
        std::unique_ptr<IMovieDAL> movieDal,
        std::istream& input,
        std::ostream& output)
        : commands(std::move(cmdList)),
          userDAL(std::move(userDal)),
          movieDAL(std::move(movieDal)),
          inputStream(input),
          outputStream(output) {}
    
    
    // Run function
    void run() {
    // initialize the menu
    ConsoleMenu menu(std::move(commands), std::move(userDAL), std::move(movieDAL), inputStream, outputStream);

    // Process commands using a loop
    while (true) {
        try {
            // Call the nextCommand method
            bool continueExecution = menu.nextCommand();
        } catch (const std::exception& e) {
            continue;
        } catch (...) {
            continue;
        }
    }
        
    }
};


// Main Function to Demonstrate Usage
int main() {
    // Create example DALs
    auto userDAL = std::make_unique<UserDALFile>();
    auto movieDAL = std::make_unique<MovieDALFile>();

    // Create example commands
    std::vector<std::unique_ptr<ICommand>> commands;
    commands.push_back(std::make_unique<Add>("Command 1"));
    commands.push_back(std::make_unique<Help>("Command 2"));

    // Create App instance
    App app(std::move(commands), std::move(userDAL), std::move(movieDAL), std::cin, std::cout);

    // Run the App
    app.run();

    return 0;
}
