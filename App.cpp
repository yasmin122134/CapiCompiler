#include "App.h"
#include <iostream>
#include <chrono>
#include <thread>

App::App(std::vector<ICommand*> cmdList,
         std::istream& input, std::ostream& output)
    : commands(cmdList),
      inputStream(input), outputStream(output) {}

void App::run(bool sec) {
    ConsoleMenu menu(commands, inputStream, outputStream);

    std::chrono::time_point<std::chrono::steady_clock> start;
    std::chrono::duration<int> duration_limit; // Fixed type for duration

    if (sec) {
        start = std::chrono::steady_clock::now();
        duration_limit = std::chrono::seconds(20); // 20 seconds
    }

    while (true) {
        try {
            bool continueExecution = menu.nextCommand();
            if (!continueExecution) {
                continue; // Exit loop if nextCommand signals termination
            }
        } catch (const std::exception& e) {
            //outputStream << "Error: " << e.what() << std::endl;
        } catch (...) {
            //outputStream << "Unknown error occurred!" << std::endl;
        }
        if( sec){
        auto now = std::chrono::steady_clock::now();
        
        // Check if 20 seconds have passed
        if (now - start >= duration_limit) {
            break;
        }
        }
    }
}
