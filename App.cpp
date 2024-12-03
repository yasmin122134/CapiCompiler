#include "App.h"

App::App(std::vector<ICommand*> cmdList,
         std::istream& input, std::ostream& output)
    : commands(cmdList),
      inputStream(input), outputStream(output) {}

void App::run() {
    ConsoleMenu menu(commands, inputStream, outputStream);

    while (true) {
        try {
            bool continueExecution = menu.nextCommand();
            if (!continueExecution) {
                break; // Exit loop if nextCommand signals termination
            }
        } catch (const std::exception& e) {
            outputStream << "Error: " << e.what() << std::endl;
        } catch (...) {
            outputStream << "Unknown error occurred!" << std::endl;
        }
    }
}
