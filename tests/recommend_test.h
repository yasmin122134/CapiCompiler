#ifndef RECOMMEND_TEST_H
#define RECOMMEND_TEST_H

#include <gtest/gtest.h>
#include <sstream>
#include "Recommend.h"

class RecommendTest : public ::testing::Test {
protected:
    Recommend recommend;
    std::stringstream output;

    void SetUp() override;
    void TearDown() override;
};

#endif // RECOMMEND_TEST_H
