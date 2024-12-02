#ifndef USER_DAL_FILE_TEST_H
#define USER_DAL_FILE_TEST_H

#include <gtest/gtest.h>
#include <fstream>  // include this for std::ofstream and std::ifstream
#include "../UserDALFile.h"
#include "../User.h"

class UserDALFileTest : public ::testing::Test {
protected:
    std::string testFile = "users.dat";

    void SetUp() override {
        // remove content of the file before each test
        std::ofstream outFile(testFile, std::ios::trunc);
        outFile.close();
    }

    void TearDown() override {
        // remove the file after each test
        std::remove(testFile.c_str());
    }
};

#endif // uSER_DAL_FILE_TEST_H