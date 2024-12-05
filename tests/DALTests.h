#ifndef DALTESTS_H
#define DALTESTS_H

#include <gtest/gtest.h>
#include "../DataAccessLayerFile.h"
#include "../Movie.h"
#include "../User.h"
#include <iostream>
using namespace std;

class DALTest : public ::testing::Test {
protected:
    void SetUp() override {
        dal = DataAccessLayer();
        dal.clear();
    }
    void TearDown() override {
        dal.clear();
    }

    DataAccessLayer dal;
    std::string userFile = "users.txt";
    std::string movieFile = "movies.txt";
};

#endif // DALTESTS_H