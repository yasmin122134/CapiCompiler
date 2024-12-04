#ifndef DALTESTS_H
#define DALTESTS_H

#include <gtest/gtest.h>
#include "../DataAccessLayer.h"
#include "../Movie.h"

class DALTest : public ::testing::Test {
protected:
    void SetUp() override {
        cout << "Setting up" << endl;
        dal = DataAccessLayer();
        dal.clear();
        cout << "Done setting up" << endl;
    }
    void TearDown() override {
        cout << "Tearing down" << endl;
        dal.clear();
        cout << "Done tearing down" << endl;
    }

    DataAccessLayer dal;
    std::string userFile = "users.txt";
    std::string movieFile = "movies.txt";
};

#endif // DALTESTS_H