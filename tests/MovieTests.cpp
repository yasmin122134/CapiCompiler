#include <gtest/gtest.h>
#include "../Movie.h"

// Test the constructor
TEST(MovieTests, Constructor) {
    Movie movie(1);
    EXPECT_EQ(movie.getId(), 1);
}

// Test the getId method
TEST(MovieTests, GetId) {
    Movie movie(2);
    EXPECT_EQ(movie.getId(), 2);
}

// Test the stream output operator
TEST(MovieTests, StreamOutputOperator) {
    Movie movie(3);
    std::stringstream ss;
    ss << movie;
    EXPECT_EQ(ss.str(), "3");
}

// Test the stream input operator
TEST(MovieTests, StreamInputOperator) {
    Movie movie(0);
    std::stringstream ss("4");
    ss >> movie;
    EXPECT_EQ(movie.getId(), 4);
}

// Test the equality operator
TEST(MovieTests, EqualityOperator) {
    Movie movie1(5);
    Movie movie2(5);
    Movie movie3(6);
    EXPECT_TRUE(movie1 == movie2);
    EXPECT_FALSE(movie1 == movie3);
}

// Test the inequality operator
TEST(MovieTests, InequalityOperator) {
    Movie movie1(7);
    Movie movie2(8);
    EXPECT_TRUE(movie1 != movie2);
    EXPECT_FALSE(movie1 != movie1);
}

// Test the less than operator
TEST(MovieTests, LessThanOperator) {
    Movie movie1(9);
    Movie movie2(10);
    EXPECT_TRUE(movie1 < movie2);
    EXPECT_FALSE(movie2 < movie1);
}//
// Created by yasmi on 05/12/2024.
//

#include "MovieTests.h"
