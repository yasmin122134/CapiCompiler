#include "UserDALFileTest.h"
#include <fstream>

// helper function to compare two vectors of movies
bool compareMovieLists(const std::vector<int>& list1, const std::vector<int>& list2) {
    return list1 == list2;
}

TEST_F(UserDALFileTest, AddAndRetrieveUserWithMovies) {
    UserDALFile dal(testFile);

    // add a user and their movies
    User user1(1);
    user1.addMovie(101);
    user1.addMovie(102);
    user1.addMovie(103);
    dal.addUser(user1);

    // retrieve the user and verify
    User retrievedUser = dal.getUser(1);
    ASSERT_EQ(retrievedUser.getId(), user1.getId()) << "User ID should match.";
    ASSERT_TRUE(compareMovieLists(retrievedUser.getMovies(), user1.getMovies())) << "Movie lists should match.";
}

TEST_F(UserDALFileTest, AddMultipleUsersWithMovies) {
    UserDALFile dal(testFile);

    // add multiple users with movies
    User user1(1);
    user1.addMovie(101);
    User user2(2);
    user2.addMovie(202);
    user2.addMovie(203);
    dal.addUser(user1);
    dal.addUser(user2);

    // retrieve and verify each user
    User retrievedUser1 = dal.getUser(1);
    User retrievedUser2 = dal.getUser(2);

    ASSERT_EQ(retrievedUser1.getId(), user1.getId()) << "User 1 ID should match.";
    ASSERT_TRUE(compareMovieLists(retrievedUser1.getMovies(), user1.getMovies())) << "User 1's movie list should match.";
    ASSERT_EQ(retrievedUser2.getId(), user2.getId()) << "User 2 ID should match.";
    ASSERT_TRUE(compareMovieLists(retrievedUser2.getMovies(), user2.getMovies())) << "User 2's movie list should match.";
}

TEST_F(UserDALFileTest, RemoveUserAndItsMovies) {
    UserDALFile dal(testFile);

    // add users and remove one
    User user1(1);
    user1.addMovie(101);
    User user2(2);
    user2.addMovie(202);
    user2.addMovie(203);
    dal.addUser(user1);
    dal.addUser(user2);
    dal.removeUser(2);

    // verify only the first user exists
    User retrievedUser1 = dal.getUser(1);
    ASSERT_EQ(retrievedUser1.getId(), user1.getId()) << "User 1 should still exist.";
    ASSERT_TRUE(compareMovieLists(retrievedUser1.getMovies(), user1.getMovies())) << "User 1's movie list should remain intact.";

    // ensure user 2 is no longer in the file
    ASSERT_THROW(dal.getUser(2), std::runtime_error) << "User 2 should not exist.";
}

TEST_F(UserDALFileTest, PersistenceAcrossRunsWithMovies) {
    // run 1: save data
    {
        UserDALFile dal(testFile);
        User user1(1);
        user1.addMovie(101);
        user1.addMovie(102);
        User user2(2);
        user2.addMovie(201);
        dal.addUser(user1);
        dal.addUser(user2);
    }

    // run 2: reload and verify data
    {
        UserDALFile dal(testFile);
        User retrievedUser1 = dal.getUser(1);
        User retrievedUser2 = dal.getUser(2);

        ASSERT_EQ(retrievedUser1.getId(), 1) << "User 1 should persist across runs.";
        ASSERT_TRUE(compareMovieLists(retrievedUser1.getMovies(), {101, 102})) << "User 1's movies should persist.";
        ASSERT_EQ(retrievedUser2.getId(), 2) << "User 2 should persist across runs.";
        ASSERT_TRUE(compareMovieLists(retrievedUser2.getMovies(), {201})) << "User 2's movies should persist.";
    }
}

TEST_F(UserDALFileTest, AddMoviesToExistingUser) {
    UserDALFile dal(testFile);

    // add a user and their movies
    User user1(1);
    user1.addMovie(101);
    dal.addUser(user1);

    // retrieve the user and add more movies
    User retrievedUser = dal.getUser(1);
    retrievedUser.addMovie(102);
    retrievedUser.addMovie(103);
    dal.addUser(retrievedUser);

    // retrieve again and verify
    User finalRetrievedUser = dal.getUser(1);
    ASSERT_EQ(finalRetrievedUser.getId(), 1) << "User ID should match.";
    ASSERT_TRUE(compareMovieLists(finalRetrievedUser.getMovies(), {101, 102, 103})) << "User's movie list should update correctly.";
}

TEST_F(UserDALFileTest, RemoveMovieFromUser) {
    UserDALFile dal(testFile);

    // add a user and their movies
    User user1(1);
    user1.addMovie(101);
    user1.addMovie(102);
    user1.addMovie(103);
    dal.addUser(user1);

    // retrieve the user and remove a movie
    User retrievedUser = dal.getUser(1);
    retrievedUser.removeMovie(102);
    dal.addUser(retrievedUser);

    // retrieve again and verify
    User finalRetrievedUser = dal.getUser(1);
    ASSERT_EQ(finalRetrievedUser.getId(), 1) << "User ID should match.";
    ASSERT_TRUE(compareMovieLists(finalRetrievedUser.getMovies(), {101, 103})) << "Movie list should update correctly after removal.";
}
TEST_F(UserDALFileTest, AddMovieToExistingUserUpdatesFile) {
    UserDALFile dal(testFile);

    // add a user to the file
    User user1(1);
    user1.addMovie(101);
    dal.addUser(user1);

    // retrieve the user and add a new movie
    User retrievedUser = dal.getUser(1);
    retrievedUser.addMovie(102);
    dal.addUser(retrievedUser); // save the updated user back to the file

    // read the file directly to verify the changes
    std::ifstream inFile(testFile);
    std::string line;
    bool userFound = false;
    while (std::getline(inFile, line)) {
        std::istringstream lineStream(line);
        int userId;
        lineStream >> userId;

        if (userId == 1) {
            userFound = true;
            std::vector<int> movies;
            int movieId;
            while (lineStream >> movieId) {
                movies.push_back(movieId);
            }

            // verify the movie list
            ASSERT_TRUE(compareMovieLists(movies, {101, 102})) << "File should reflect updated movie list for the user.";
        }
    }

    ASSERT_TRUE(userFound) << "User 1 should be found in the file.";
}
