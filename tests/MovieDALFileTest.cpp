
#include "MovieDALFileTest.h"
#include "../MovieDALFile.h"
#include "../Movie.h"
#include <gtest/gtest.h>
#include <fstream>


TEST_F(MovieDALFileTest, AddAndRetrieveMovie) {
    MovieDALFile dal;

    // add a Movie and retrieve it
    Movie Movie1(1);
    dal.addMovie(Movie1);
    Movie retrievedMovie = dal.getMovie(1);

    ASSERT_EQ(retrievedMovie.getId(), Movie1.getId()) << "Movie ID should match after saving and reloading.";
}

TEST_F(MovieDALFileTest, AddMultipleMovies) {
    MovieDALFile dal;

    int num = 100;
    vector<Movie> Movies(num);

    // add multiple Movies
    for (size_t i = 0; i < num; i++) {
        Movie Movie(i);
        Movies[i] = Movie;
        dal.addMovie(Movie);
    }

    // retrieve and verify each Movie
    vector<Movie> retrievedMovies(num);
    for (size_t i = 0; i < num; i++) {
        retrievedMovies[i] = dal.getMovie(i);
    }

    // verify that all Movies were added and retrieved correctly
    for (size_t i = 0; i < num; i++) {
        ASSERT_EQ(retrievedMovies[i].getId(), Movies[i].getId()) << "Movie ID should match.";
    }
}

TEST_F(MovieDALFileTest, RemoveActuallyRemoves) {
    MovieDALFile dal;

    // add a Movie and remove it
    Movie Movie1(1);
    Movie Movie2(2);
    dal.addMovie(Movie1);
    dal.addMovie(Movie2);
    dal.removeMovie(1);
    dal.removeMovie(2);

    // check if the Movie was removed
    ifstream inFile(testFile);
    int numLines = 0;
    int movieCount = 0;
    Movie tempMovie;
    while(inFile >> tempMovie) {
        movieCount++;
    }
    // get the number of lines in the file by reading lines
    std::string line;
    while (std::getline(inFile, line)) {
        numLines++;
    }

    // check if inFile is empty
    ASSERT_TRUE(numLines == 0) << "File should be empty after removing all Movies.";
    ASSERT_TRUE(movieCount == 0) << "File should be empty after removing all Movies.";
    ASSERT_FALSE(inFile) << "File should be empty after removing all Movies.";
}

TEST_F(MovieDALFileTest, getMovieAddsMovie) {
    MovieDALFile dal;

    // add Movies and remove one
    Movie Movie1(1);
    dal.addMovie(Movie1);
    dal.removeMovie(1);
    
    Movie retrievedMovie1 = dal.getMovie(1);
    ASSERT_EQ(retrievedMovie1.getId(), Movie1.getId()) << "Movie 1 ID should match."; // get should add the movie back
    ASSERT_EQ(retrievedMovie1, Movie1) << "using the comperator should work";
    ASSERT_TRUE(dal.doesExist(Movie1)) << "Movie 1 should exist in the file.";
}

TEST_F(MovieDALFileTest, PersistenceAcrossRuns) {
    // Run 1: save data
    {
        MovieDALFile dal;
        dal.addMovie(Movie(1));
        dal.addMovie(Movie(2));
        dal.getMovie(3);
    }

    // Run 2: reload and verify data
    {
        MovieDALFile dal;
        ASSERT_TRUE(dal.doesExist(Movie(1))) << "Movie 1 should exist in the file.";
        ASSERT_TRUE(dal.doesExist(Movie(2))) << "Movie 2 should exist in the file.";
        ASSERT_TRUE(dal.doesExist(Movie(3))) << "Movie 3 should not exist in the file.";
    }
}

// Test: ensure no duplicates are created when adding the same Movie multiple times
TEST_F(MovieDALFileTest, NoDuplicatesOnAdd) {
    MovieDALFile dal;

    Movie Movie1(1);
    dal.addMovie(Movie1);
    dal.addMovie(Movie1); // Add the same Movie again
    dal.addMovie(Movie(2));
    dal.addMovie(Movie(3));


    // retrieve Movie and check it was added only once
    Movie retrievedMovie = dal.getMovie(1);
    ASSERT_EQ(retrievedMovie.getId(), Movie1.getId()) << "Movie ID should match.";
    
    // read the file directly and count the number of Movies
    std::ifstream inFile(testFile);
    int MovieCount = 0;
    Movie tempMovie;
    while (inFile >> tempMovie) {
        MovieCount++;
    }

    // check there is exactly 3 Movie in the file
    ASSERT_EQ(MovieCount, 3) << "There should be exactly one Movie in the file.";
}

// Test: ensure that getMovie doesn't create an extra Movie record
TEST_F(MovieDALFileTest, GetMovieDoesNotCreateExtraMovie) {
    MovieDALFile dal;

    // try to get a Movie that doesn't exist
    dal.addMovie(Movie(2));
    Movie retrievedMovie = dal.getMovie(2);
    dal.getMovie(3);
    dal.getMovie(2);
    dal.getMovie(3);

    // check if a new Movie was created, it should not be
    std::ifstream inFile(testFile);
    int MovieCount = 0;
    Movie tempMovie;
    while (inFile) {
        inFile >> tempMovie;
        if (inFile) {
            MovieCount++;
        }
    }

    // ensure that no new Movie was created
    ASSERT_EQ(MovieCount, 2) << "No new Movie should have been added to the file.";
}

// Test: check that removeMovie actually removes the Movie from the file
TEST_F(MovieDALFileTest, RemoveRemovesOnlyOneMovie) {
    MovieDALFile dal;

    // add Movies and remove one
    Movie Movie1(1);
    Movie Movie2(2);
    Movie Movie3(3);
    dal.addMovie(Movie1);
    dal.addMovie(Movie2);
    dal.addMovie(Movie3);
    dal.removeMovie(2);

    // open the file and check contents directly
    std::ifstream inFile(testFile);
    int MovieCount = 0;
    Movie tempMovie;
    bool Movie2Found = false;
    while (inFile) {
        inFile >> tempMovie;
        if (inFile) {
            MovieCount++;
            if (tempMovie.getId() == 2) {
                Movie2Found = true;
            }
        }
    }

    // verify that Movie 2 was removed and Movie 1 remains
    ASSERT_EQ(MovieCount, 2) << "There should be one Movie remaining in the file.";
    ASSERT_FALSE(Movie2Found) << "Movie 2 should not be found in the file.";
}

// Test: adding and Removing a Large Number of Movies
TEST_F(MovieDALFileTest, LargeNumberOfMovies) {
    MovieDALFile dal;

    // add 10,000 Movies
    for (int i = 0; i < 10000; i++) {
        Movie Movie(i + 1);
        dal.addMovie(Movie);
    }

    // retrieve the last Movie to ensure all Movies were added
    Movie retrievedMovie = dal.getMovie(10000);
    ASSERT_EQ(retrievedMovie.getId(), 10000) << "Last Movie should be retrievable.";

    // remove 5000 Movies and verify that the remaining Movies still exist
    for (int i = 0; i < 5000; i++) {
        dal.removeMovie(i + 1);
    }

    // verify that the Movies 5001 to 10000 still exist
    for (int i = 5001; i <= 10000; i++) {
        ASSERT_TRUE(dal.doesExist(Movie(i))) << "Movie ID " << i << " should still exist.";
    }
}
