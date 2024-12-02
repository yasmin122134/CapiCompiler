#include "add_test.h"
#include <sstream>

TEST_F(AddTest, AddUserWithMultipleMovies) {
    UserDALFile dal = UserDALFile();
    MovieDALFile movieDal = MovieDALFile();
    Add cmd(&dal, &movieDal);
    cmd.execute("add 123 1001 1002 1003");

    User user(123);
    ASSERT_TRUE(dal.doesExist(user));
    
    user = dal.getUser(123);
    EXPECT_EQ(user.getMovieVec().size(), 3);
}

TEST_F(AddTest, AddDuplicateUser) {
    UserDALFile dal = UserDALFile();
    MovieDALFile movieDal = MovieDALFile();
    Add cmd(&dal, &movieDal);
    cmd.execute("add 123 1001");
    cmd.execute("add 123 1002");
    
    User user(123);
    ASSERT_TRUE(dal.doesExist(user));
    user = dal.getUser(123);
    EXPECT_EQ(user.getMovieVec().size(), 2);
}

TEST_F(AddTest, AddUserWithNoMovies) {
    UserDALFile dal = UserDALFile();
    MovieDALFile movieDal = MovieDALFile();
    Add cmd(&dal, &movieDal);
    cmd.execute("add 123");
    
    std::stringstream output;
    cmd.print(output);
    EXPECT_EQ(output.str(), "Error: No movies specified for user\n");
}

TEST_F(AddTest, AddUserWithNonNumericIds) {
    UserDALFile dal = UserDALFile();
    MovieDALFile movieDal = MovieDALFile();
    Add cmd(&dal, &movieDal);
    cmd.execute("add abc 1001");
    std::stringstream output1;
    cmd.print(output1);
    EXPECT_EQ(output1.str(), "Error: Invalid user ID format\n");
    
    cmd.execute("add 123 abc");
    std::stringstream output2;
    cmd.print(output2);
    EXPECT_EQ(output2.str(), "Error: Invalid movie ID format\n");
}

TEST_F(AddTest, IllegalCommandsDoNotModifyState) {
    UserDALFile dal = UserDALFile();
    MovieDALFile movieDal = MovieDALFile();
    Add cmd(&dal, &movieDal);
    cmd.execute("add abc 1001");  // Invalid user ID
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added
    
    cmd.execute("add 123");  // No movies
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added
    
    cmd.execute("add 123 abc");  // Invalid movie ID
    EXPECT_EQ(dal.getAllUsers().size(), 0);  // No user should be added
}