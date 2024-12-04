#pragma once

// Includes necessary headers
#include <iostream>
#include <memory>
#include <vector>
#include "commands/ICommand.h"
#include "commands/Help.h"
#include "commands/Recommend.h"
#include "commands/Add.h"
#include "App.h"

// Declaration of the MainApp class
class Main {
public:
    // Static function to initialize and run the application
    static int main();
};
