#include "add_test.h"
#include "../DataAccessLayerFile.h"
#include <sstream>
#include <iostream>

TEST_F(AddTest, AddUserWithMultipleMovies) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    Add cmd(&dal);
    cmd.execute("123 1001 1002 1003");

    User user(123);
    ASSERT_TRUE(dal.doesExistEqual(user));
    
    user = dal.getUser(123);
    EXPECT_EQ(user.getMovieVec().size(), 3);
}

TEST_F(AddTest, AddDuplicateUser) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    dal.clear();
    Add cmd(&dal);
    cmd.execute("123 1001");
    cmd.execute("123 1002");
    
    User user = dal.getUser(123);
    ASSERT_TRUE(dal.doesExistEqual(user));
    EXPECT_EQ(user.getMovieVec().size(), 2);

}

TEST_F(AddTest, AddUserWithNoMovies) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    dal.clear();
    Add cmd(&dal);
    
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    
    cmd.execute("123");  // Execute the command
    
    std::cout.rdbuf(oldCoutBuffer);  // Restore original cout buffer
    
    EXPECT_EQ(buffer.str(), "");
    
}

TEST_F(AddTest, AddUserWithNonNumericIds) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    dal.clear();
    Add cmd(&dal);
    
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());  // Redirect cout to buffer
    
    cmd.execute("1001");
    
    std::cout.rdbuf(oldCoutBuffer);  // Restore original cout buffer
    
    EXPECT_EQ(buffer.str(), "");
    
    cmd.execute("123 abc");
    std::stringstream output2;
    EXPECT_EQ(buffer.str(), "");
    
}

TEST_F(AddTest, IllegalCommandsDoNotModifyState) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    dal.clear();
    Add cmd(&dal);
    
    cmd.execute("abc 1001");  // Invalid user ID
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added
    
    cmd.execute("123");  // No movies
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added
    
    cmd.execute("123 abc");  // Invalid movie ID
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added

}