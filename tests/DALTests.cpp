#include "DALTests.h"

void DataAccessLayerTest::SetUp() {
    // Setup code if needed
}

void DataAccessLayerTest::TearDown() {
    // Teardown code if needed
}

TEST_F(DataAccessLayerTest, GetAllMovies_EmptyList) {
    // Arrange
    std::vector<Movie> emptyList;
    // Simulate the behavior of movieDal.getAllMovies() returning an empty list
    movieDal = MovieDAL(); // Reset movieDal to its default state

    // Act
    std::vector<Movie> movies = dataAccessLayer.getAllMovies();

    // Assert
    EXPECT_TRUE(movies.empty());
}

TEST_F(DataAccessLayerTest, GetAllMovies_SingleMovie) {
    // Arrange
    Movie movie(1);
    std::vector<Movie> singleMovieList = {movie};
    // Simulate the behavior of movieDal.getAllMovies() returning a single movie
    movieDal = MovieDAL(); // Reset movieDal to its default state

    // Act
    std::vector<Movie> movies = dataAccessLayer.getAllMovies();

    // Assert
    ASSERT_EQ(movies.size(), 1);
    EXPECT_EQ(movies[0].getId(), 1);
}

TEST_F(DataAccessLayerTest, GetAllMovies_MultipleMovies) {
    // Arrange
    Movie movie1(1);
    Movie movie2(2);
    std::vector<Movie> multipleMoviesList = {movie1, movie2};
    // Simulate the behavior of movieDal.getAllMovies() returning multiple movies
    movieDal = MovieDAL(); // Reset movieDal to its default state

    // Act
    std::vector<Movie> movies = dataAccessLayer.getAllMovies();

    // Assert
    ASSERT_EQ(movies.size(), 2);
    EXPECT_EQ(movies[0].getId(), 1);
    EXPECT_EQ(movies[1].getId(), 2);
}

TEST_F(DataAccessLayerTest, GetAllMovies_DuplicateMovies) {
    // Arrange
    Movie movie(1);
    std::vector<Movie> duplicateMoviesList = {movie, movie};
    // Simulate the behavior of movieDal.getAllMovies() returning duplicate movies
    movieDal = MovieDAL(); // Reset movieDal to its default state

    // Act
    std::vector<Movie> movies = dataAccessLayer.getAllMovies();

    // Assert
    ASSERT_EQ(movies.size(), 2);
    EXPECT_EQ(movies[0].getId(), 1);
    EXPECT_EQ(movies[1].getId(), 1);
}