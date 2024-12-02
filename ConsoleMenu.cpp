#include <iostream>
#include <string>
#include "ICommand.h"

// Assuming Command is a simple alias for std::string. Modify as needed.
using Command = std::string;

class ConsoleMenu : public IMenu {
public:
    // Implement the nextCommand method
private:
    std::vector<std::unique_ptr<ICommand>> commands;
    std::unique_ptr<IUserDAL> userDAL;
    std::unique_ptr<IMovieDAL> movieDAL;
    std::istream& inputStream;
    std::ostream& outputStream;

public:
    // Constructor
    ConsoleMenu(std::vector<std::unique_ptr<ICommand>> cmdList,
        std::unique_ptr<IUserDAL> userDal,
        std::unique_ptr<IMovieDAL> movieDal,
        std::istream& input,
        std::ostream& output)
        : commands(std::move(cmdList)),
          userDAL(std::move(userDal)),
          movieDAL(std::move(movieDal)),
          inputStream(input),
          outputStream(output) {}
    
    // Next Command function
     bool nextCommand() override {

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
    }

    }
    // Implement the displayError method
    void displayError(const std::string errorName) override {
        std::cerr << "Error: " << errorName << std::endl;
    }
};
