#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>
#include "commands/ICommand.h"
#include "IMenu.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"

// Assuming Command is a simple alias for std::string. Modify as needed.
using namespace std;
using CommandList = std::vector<std::unique_ptr<ICommand>>;
using UserDALPtr = std::unique_ptr<IUserDAL>;
using MovieDALPtr = std::unique_ptr<IMovieDAL>;

class ConsoleMenu : public IMenu {
private:
    CommandList commands;
    UserDALPtr userDAL;
    MovieDALPtr movieDAL;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    // Constructor


    ConsoleMenu(CommandList cmdList,
                UserDALPtr userDal,
                MovieDALPtr movieDal,
        std::istream& input,
        std::ostream& output)
        : commands(std::move(cmdList)),
          userDAL(std::move(userDal)),
          movieDAL(std::move(movieDal)),
          inputStream(input),
          outputStream(output) {}
    
    // Next Command function
     bool nextCommand() override {
        std::string line;
        if (!std::getline(inputStream, line) || line.empty()) {
            return false; // Signal to stop if input is empty or EOF
        }

        // Parse the first word as the command name
        std::istringstream lineStream(line);
        std::string commandName;
        lineStream >> commandName;

        // Extract the rest of the line as arguments
        std::string args;
        std::getline(lineStream, args);
        args.erase(0, args.find_first_not_of(" \t")); // Trim leading whitespace

        // Find the matching command in the vector
        auto it = std::find_if(commands.begin(), commands.end(),
                            [&commandName](const std::unique_ptr<ICommand>& cmd) {
                                return cmd->getCommandName() == commandName;
                            });

        if (it != commands.end()) {
            // Command found, execute it
            (*it)->execute(args);
            return true;
        }

        // Command not found
        return false; // Continue accepting commands
    };

    // Implement the displayError method
    void displayError(const std::string errorName) override {
        std::cerr << "Error: " << errorName << std::endl;
    }
};
