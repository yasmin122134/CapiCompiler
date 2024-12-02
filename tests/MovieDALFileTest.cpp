
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

    // add multiple Movies
    Movie Movie1(1);
    Movie Movie2(2);
    dal.addMovie(Movie1);
    dal.addMovie(Movie2);

    // retrieve and verify each Movie
    Movie retrievedMovie2 = dal.getMovie(2);
    Movie retrievedMovie1 = dal.getMovie(1);

    ASSERT_EQ(retrievedMovie1.getId(), Movie1.getId()) << "Movie 1 ID should match.";
    ASSERT_EQ(retrievedMovie2.getId(), Movie2.getId()) << "Movie 2 ID should match.";
}

TEST_F(MovieDALFileTest, RemoveMovie) {
    MovieDALFile dal;

    // add Movies and remove one
    Movie Movie1(1);
    Movie Movie2(2);
    dal.addMovie(Movie1);
    dal.addMovie(Movie2);
    dal.removeMovie(2);

    // verify only the second Movie exists
    ASSERT_EQ(dal.getMovie(2).getId(), Movie2.getId()) << "Movie 2 ID should match.";
    Movie retrievedMovie1 = dal.getMovie(1);
    ASSERT_EQ(retrievedMovie1.getId(), Movie1.getId()) << "Movie 1 should still exist.";
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
        Movie retrievedMovie1 = dal.getMovie(1);
        Movie retrievedMovie2 = dal.getMovie(2);
        Movie retrievedMovie3 = dal.getMovie(3);

        ASSERT_EQ(retrievedMovie1.getId(), 1) << "Movie 1 should persist across runs.";
        ASSERT_EQ(retrievedMovie2.getId(), 2) << "Movie 2 should persist across runs.";
        ASSERT_EQ(retrievedMovie3.getId(), 3) << "Movie 3 should persist across runs.";
    }
}

// Test: ensure no duplicates are created when adding the same Movie multiple times
TEST_F(MovieDALFileTest, NoDuplicatesOnAdd) {
    MovieDALFile dal;

    Movie Movie1(1);
    dal.addMovie(Movie1);
    dal.addMovie(Movie1); // Add the same Movie again

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

    // check there is exactly 1 Movie in the file
    ASSERT_EQ(MovieCount, 1) << "There should be exactly one Movie in the file.";
}

// Test: ensure that getMovie doesn't create an extra Movie record
TEST_F(MovieDALFileTest, GetMovieDoesNotCreateExtraMovie) {
    MovieDALFile dal;

    // try to get a Movie that doesn't exist
    dal.addMovie(Movie(2));
    Movie retrievedMovie = dal.getMovie(2);

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
    ASSERT_EQ(MovieCount, 1) << "No new Movie should have been added to the file.";
}

// Test: check that removeMovie actually removes the Movie from the file
TEST_F(MovieDALFileTest, RemoveMovieFromFile) {
    MovieDALFile dal;

    // add Movies and remove one
    Movie Movie1(1);
    Movie Movie2(2);
    dal.addMovie(Movie1);
    dal.addMovie(Movie2);
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
    ASSERT_EQ(MovieCount, 1) << "There should be one Movie remaining in the file.";
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
        Movie retrievedMovie = dal.getMovie(i);
        ASSERT_EQ(retrievedMovie.getId(), i) << "Movie ID " << i << " should still exist.";
    }
}
