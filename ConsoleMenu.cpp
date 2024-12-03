#include "ConsoleMenu.h"

ConsoleMenu::ConsoleMenu(std::vector<ICommand*> cmdList,
                         std::istream& input, std::ostream& output)
    : commands(cmdList), inputStream(input), outputStream(output) {}

bool ConsoleMenu::nextCommand() {
    outputStream << ">"; // Display prompt
    std::string line;
    if (!std::getline(inputStream, line) || line.empty()) {
        return false;
    }

    std::istringstream lineStream(line);
    std::string commandName;
    lineStream >> commandName;

    std::string args;
    std::getline(lineStream, args);
    args.erase(0, args.find_first_not_of(" \t"));

    auto it = std::find_if(commands.begin(), commands.end(),
        [&commandName](ICommand* cmd) {
            return cmd->getCommandName() == commandName;
        });

    if (it != commands.end()) {
        (*it)->execute(args);
    } else {
        displayError("Command not found: " + commandName);
    }

    return true;
}

void ConsoleMenu::displayError(const std::string& errorName) {
    outputStream << "Error: " << errorName << std::endl;
}
