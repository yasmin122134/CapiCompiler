#ifndef Movie_DAL_FILE_TEST_H
#define Movie_DAL_FILE_TEST_H

#include <gtest/gtest.h>
#include <fstream>  // include this for std::ofstream and std::ifstream
#include "../MovieDALFile.h"
#include "../Movie.h"

class MovieDALFileTest : public ::testing::Test {
protected:
    std::string testFile = "test_Movies.dat";

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

#endif // movie_DAL_FILE_TEST_H
