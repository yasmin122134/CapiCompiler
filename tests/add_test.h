#ifndef ADD_TEST_H
#define ADD_TEST_H

#include <gtest/gtest.h>
#include "../commands/Add.h"
#include "../User.h"
#include "../Movie.h"
#include "../UserDALFile.h"
#include "../MovieDALFile.h"
#include <fstream>
#include <iostream>  // for debug prints

class AddTest : public ::testing::Test {
protected:
    std::string testFile = "test_users.dat";
    IUserDAL* userDAL;
    IMovieDAL* movieDAL;

    void SetUp() override {
        std::cout << "\n[TEST SETUP] Starting test setup..." << std::endl;
        
        // remove content of the file before each test
        std::ofstream outFile(testFile, std::ios::trunc);
        if (!outFile.is_open()) {
            std::cerr << "[TEST SETUP ERROR] Failed to open file for truncation: " << testFile << std::endl;
        }
        outFile.close();
        std::cout << "[TEST SETUP] Test file truncated: " << testFile << std::endl;
        
        userDAL = new UserDALFile();
        if (!userDAL) {
            std::cerr << "[TEST SETUP ERROR] Failed to create UserDALFile instance" << std::endl;
        }
        userDAL->clear();
        std::cout << "[TEST SETUP] UserDALFile initialized and cleared" << std::endl;
        
        movieDAL = new MovieDALFile();
        if (!movieDAL) {
            std::cerr << "[TEST SETUP ERROR] Failed to create MovieDALFile instance" << std::endl;
        }
        movieDAL->clear();
        std::cout << "[TEST SETUP] MovieDALFile initialized and cleared" << std::endl;
    }

    void TearDown() override {
        std::cout << "\n[TEST TEARDOWN] Starting test cleanup..." << std::endl;
        
        delete userDAL;
        std::cout << "[TEST TEARDOWN] UserDAL deleted" << std::endl;
        
        delete movieDAL;
        std::cout << "[TEST TEARDOWN] MovieDAL deleted" << std::endl;
        
        if (std::remove(testFile.c_str()) != 0) {
            std::cerr << "[TEST TEARDOWN ERROR] Failed to remove test file: " << testFile << std::endl;
        } else {
            std::cout << "[TEST TEARDOWN] Test file removed: " << testFile << std::endl;
        }
    }
};

#endif
