#include <gtest/gtest.h>
#include "../User.h"
#include "../Movie.h"

TEST(UserTests, ConstructorWithId) {
    User user(1);
    EXPECT_EQ(user.getId(), 1);
    EXPECT_TRUE(user.getMovieSet().empty());
}

TEST(UserTests, ConstructorWithIdAndMovieVec) {
    Movie movie1(1);
    Movie movie2(2);
    vector<Movie> movies = {movie1, movie2};
    User user(1, movies);
    EXPECT_EQ(user.getId(), 1);
    EXPECT_EQ(user.getMovieSet().size(), 2);
}

TEST(UserTests, ConstructorWithIdAndMovieSet) {
    Movie movie1(1);
    Movie movie2(2);
    set<Movie> movies = {movie1, movie2};
    User user(1, movies);
    EXPECT_EQ(user.getId(), 1);
    EXPECT_EQ(user.getMovieSet().size(), 2);
}

TEST(UserTests, AddMovie) {
    User user(1);
    Movie movie(2);
    user.addMovie(movie);
    EXPECT_EQ(user.getMovieSet().size(), 1);
    set<Movie> movies = user.getMovieSet();
    EXPECT_EQ(movies.begin()->getId(), 2);
}

TEST(UserTests, AddMovieVec) {
    User user(1);
    Movie movie1(1);
    Movie movie2(2);
    vector<Movie> movies = {movie1, movie2};
    user.addMovieVec(movies);
    EXPECT_EQ(user.getMovieSet().size(), 2);
    user.addMovie(Movie(3));
    user.addMovie(Movie(4));
    movies = {Movie(5), Movie(4)};
    user.addMovieVec(movies);
    EXPECT_EQ(user.getMovieSet().size(), 5);
}

TEST(UserTests, RemoveMovie) {
    Movie movie1(1);
    Movie movie2(2);
    set<Movie> movies = {movie1, movie2};
    User user(1, movies);
    user.removeMovie(movie1);
    EXPECT_EQ(user.getMovieSet().size(), 1);
}

TEST(UserTests, StreamOperators) {
    User user(1);
    Movie movie1(1);
    Movie movie2(2);
    user.addMovie(movie1);
    user.addMovie(movie2);

    std::stringstream ss;
    ss << user;
    User user2(0);
    ss >> user2;

    EXPECT_EQ(user, user2);
}

TEST(UserTests, ComparisonOperators) {
    Movie movie1(1);
    Movie movie2(1);
    set<Movie> movies1 = {movie1, movie2};
    set<Movie> movies2 = {movie1};

    User user1(1, movies1);
    User user2(1, movies1);
    User user3(2, movies2);

    EXPECT_TRUE(user1 == user2);
    EXPECT_FALSE(user1 == user3);
    EXPECT_TRUE(user1 != user3);
    EXPECT_FALSE(user1 != user2);
    EXPECT_TRUE(user1 < user3);
    EXPECT_FALSE(user3 < user1);
}//
// Created by yasmi on 05/12/2024.
//

#include "UserTests.h"
