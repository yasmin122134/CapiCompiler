#include "App.h"
#include <iostream>
#include <chrono>
#include <thread>

App::App(std::vector<ICommand*> cmdList,
         std::istream& input, std::ostream& output)
    : commands(cmdList),
      inputStream(input), outputStream(output) {}

void App::run() {
    ConsoleMenu menu(commands, inputStream, outputStream);
    auto start = std::chrono::steady_clock::now();
    auto duration_limit = std::chrono::seconds(20); // 20 seconds

    while (true) {
        try {
            bool continueExecution = menu.nextCommand();
            if (!continueExecution) {
                continue; // Exit loop if nextCommand signals termination
            }
        } catch (const std::exception& e) {
            outputStream << "Error: " << e.what() << std::endl;
        } catch (...) {
            outputStream << "Unknown error occurred!" << std::endl;
        }
        auto now = std::chrono::steady_clock::now();
        
        // Check if 20 seconds have passed
        if (now - start >= duration_limit) {
            break;
        }
    }
}
