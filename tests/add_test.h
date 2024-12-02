#ifndef ADD_TEST_H
#define ADD_TEST_H

#include <gtest/gtest.h>
#include <fstream>
#include "../UserDALFile.h"
#include "../MovieDALFile.h"
#include "../commands/Add.h"
#include "../User.h"
#include <vector>

class AddTest : public ::testing::Test {
protected:
    std::string testFile = "users.dat";
    std::vector<Movie> testMovies;
    User testUser;

    void SetUp() override {
        // remove content of the file before each test
        std::ofstream outFile(testFile, std::ios::trunc);
        outFile.close();

        // Initialize test user and movies
        testUser = User(1);  // Create user with ID 1
        
        // Create some test movies
        testMovies = {
            Movie(1),
            Movie(2),
            Movie(3)
        };
    }

    void TearDown() override {
        // remove the file after each test
        std::remove(testFile.c_str());
    }
};

#endif // ADD_TEST_H
