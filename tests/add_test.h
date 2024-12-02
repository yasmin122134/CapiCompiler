#ifndef ADD_TEST_H
#define ADD_TEST_H

#include <gtest/gtest.h>
#include "../commands/Add.h"
#include "../UserDALFile.h"
#include "../MovieDALFile.h"
#include "../User.h"
#include "../Movie.h"

class AddTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }

    void TearDown() override {
        // Any cleanup code would go here
    }
};

#endif // ADD_TEST_H
