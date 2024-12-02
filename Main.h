#pragma once

// Includes necessary headers
#include <iostream>
#include <memory>
#include <vector>
#include "ICommand.h"
#include "IUserDAL.h"
#include "IMovieDAL.h"
#include "Help.h"
#include "Recommend.h"
#include "AddMovie.h"
#include "UserDAL.h"
#include "MovieDAL.h"
#include "App.h"

// Declaration of the MainApp class
class Main {
public:
    // Static function to initialize and run the application
    static int main();
};
