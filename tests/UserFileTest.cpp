#include "UserFileTest.h'
#include <fstream>

TEST_F(UserDALFileTest, AddAndRetrieveUser) {
    UserDALFile dal(testFile);

    // add a user and retrieve it
    User user1(1);
    dal.addUser(user1);

    User retrievedUser = dal.getUser(1);

    ASSERT_EQ(retrievedUser.getId(), user1.getId()) << "User ID should match after saving and reloading.";
}

TEST_F(UserDALFileTest, AddMultipleUsers) {
    UserDALFile dal(testFile);

    // add multiple users
    User user1(1);
    User user2(2);
    dal.addUser(user1);
    dal.addUser(user2);

    // retrieve and verify each user
    User retrievedUser2 = dal.getUser(2);
    User retrievedUser1 = dal.getUser(1);

    ASSERT_EQ(retrievedUser1.getId(), user1.getId()) << "User 1 ID should match.";
    ASSERT_EQ(retrievedUser2.getId(), user2.getId()) << "User 2 ID should match.";
}

TEST_F(UserDALFileTest, RemoveUser) {
    UserDALFile dal(testFile);

    // add users and remove one
    User user1(1);
    User user2(2);
    dal.addUser(user1);
    dal.addUser(user2);
    dal.removeUser(2);

    // verify only the second user exists
    ASSERT_EQ(dal.getUser(2).getId(), user2.getId()) << "User 2 ID should match.";
    User retrievedUser1 = dal.getUser(1);
    ASSERT_EQ(retrievedUser1.getId(), user1.getId()) << "User 1 should still exist.";
}

TEST_F(UserDALFileTest, PersistenceAcrossRuns) {
    // Run 1: save data
    {
        UserDALFile dal(testFile);
        dal.addUser(User(1));
        dal.addUser(User(2));
        dal.getUser(3);
    }

    // Run 2: reload and verify data
    {
        UserDALFile dal(testFile);
        User retrievedUser1 = dal.getUser(1);
        User retrievedUser2 = dal.getUser(2);
        User retrievedUser3 = dal.getUser(3);

        ASSERT_EQ(retrievedUser1.getId(), 1) << "User 1 should persist across runs.";
        ASSERT_EQ(retrievedUser2.getId(), 2) << "User 2 should persist across runs.";
        ASSERT_EQ(retrievedUser3.getId(), 3) << "User 3 should persist across runs.";
    }
}

// Test: ensure no duplicates are created when adding the same user multiple times
TEST_F(UserDALFileTest, NoDuplicatesOnAdd) {
    UserDALFile dal(testFile);

    User user1(1);
    dal.addUser(user1);
    dal.addUser(user1); // Add the same user again

    // retrieve user and check it was added only once
    User retrievedUser = dal.getUser(1);
    ASSERT_EQ(retrievedUser.getId(), user1.getId()) << "User ID should match.";
    
    // read the file directly and count the number of users
    std::ifstream inFile(testFile);
    int userCount = 0;
    User tempUser;
    while (inFile) {
        tempUser.loadFromStream(inFile);
        if (inFile) {
            userCount++;
        }
    }

    // check there is exactly 1 user in the file
    ASSERT_EQ(userCount, 1) << "There should be exactly one user in the file.";
}

// Test: ensure that getUser doesn't create an extra user record
TEST_F(UserDALFileTest, GetUserDoesNotCreateExtraUser) {
    UserDALFile dal(testFile);

    // try to get a user that doesn't exist
    User retrievedUser = dal.getUser(999); // Non-existing user

    // check if a new user was created, it should not be
    std::ifstream inFile(testFile);
    int userCount = 0;
    User tempUser;
    while (inFile) {
        tempUser.loadFromStream(inFile);
        if (inFile) {
            userCount++;
        }
    }

    // ensure that no new user was created
    ASSERT_EQ(userCount, 0) << "No new user should have been added to the file.";
}

// Test: check that removeUser actually removes the user from the file
TEST_F(UserDALFileTest, RemoveUserFromFile) {
    UserDALFile dal(testFile);

    // add users and remove one
    User user1(1);
    User user2(2);
    dal.addUser(user1);
    dal.addUser(user2);
    dal.removeUser(2);

    // open the file and check contents directly
    std::ifstream inFile(testFile);
    int userCount = 0;
    User tempUser;
    bool user2Found = false;
    while (inFile) {
        tempUser.loadFromStream(inFile);
        if (inFile) {
            userCount++;
            if (tempUser.getId() == 2) {
                user2Found = true;
            }
        }
    }

    // verify that user 2 was removed and user 1 remains
    ASSERT_EQ(userCount, 1) << "There should be one user remaining in the file.";
    ASSERT_FALSE(user2Found) << "User 2 should not be found in the file.";
}

// Test: adding and Removing a Large Number of Users
TEST_F(UserDALFileTest, LargeNumberOfUsers) {
    UserDALFile dal(testFile);

    // add 10,000 users
    for (int i = 0; i < 10000; i++) {
        User user(i + 1);
        dal.addUser(user);
    }

    // retrieve the last user to ensure all users were added
    User retrievedUser = dal.getUser(10000);
    ASSERT_EQ(retrievedUser.getId(), 10000) << "Last user should be retrievable.";

    // remove 5000 users and verify that the remaining users still exist
    for (int i = 0; i < 5000; i++) {
        dal.removeUser(i + 1);
    }

    // verify that the users 5001 to 10000 still exist
    for (int i = 5001; i <= 10000; i++) {
        User retrievedUser = dal.getUser(i);
        ASSERT_EQ(retrievedUser.getId(), i) << "User ID " << i << " should still exist.";
    }
}
