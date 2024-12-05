#include <gtest/gtest.h>
#include <sstream>
#include "../commands/Recommend.h"
#include "../MovieDALFile.h"
#include "../UserDALFile.h"

class RecommendTest : public ::testing::Test {
protected:
    MovieDALFile* movieDal;
    UserDALFile* userDal;
    Recommend* recommend;
    std::stringstream output;

    void SetUp() override {
        // Initialize DAL objects
        movieDal = new MovieDALFile();
        userDal = new UserDALFile();
        
        // Add test movies (IDs 100-116)
        for (int i = 100; i <= 116; i++) {
            Movie movie(i);
            movieDal->addMovie(movie);
        }
        
        // Add users with their watched movies
        User user1(1);
        user1.addMovie(Movie(103));
        user1.addMovie(Movie(102));
        user1.addMovie(Movie(101));
        user1.addMovie(Movie(100));
        userDal->addUser(user1);
        
        User user2(2);
        user2.addMovie(Movie(106));
        user2.addMovie(Movie(105));
        user2.addMovie(Movie(104));
        user2.addMovie(Movie(102));
        user2.addMovie(Movie(101));
        userDal->addUser(user2);
        
        User user3(3);
        user3.addMovie(Movie(108));
        user3.addMovie(Movie(107));
        user3.addMovie(Movie(105));
        user3.addMovie(Movie(104));
        user3.addMovie(Movie(100));
        userDal->addUser(user3);
        
        User user4(4);
        user4.addMovie(Movie(110));
        user4.addMovie(Movie(109));
        user4.addMovie(Movie(107));
        user4.addMovie(Movie(106));
        user4.addMovie(Movie(105));
        user4.addMovie(Movie(101));
        userDal->addUser(user4);
        
        User user5(5);
        user5.addMovie(Movie(111));
        user5.addMovie(Movie(108));
        user5.addMovie(Movie(105));
        user5.addMovie(Movie(103));
        user5.addMovie(Movie(102));
        user5.addMovie(Movie(100));
        userDal->addUser(user5);
        
        User user6(6);
        user6.addMovie(Movie(113));
        user6.addMovie(Movie(112));
        user6.addMovie(Movie(111));
        user6.addMovie(Movie(110));
        user6.addMovie(Movie(104));
        user6.addMovie(Movie(103));
        user6.addMovie(Movie(100));
        userDal->addUser(user6);
        
        User user7(7);
        user7.addMovie(Movie(110));
        user7.addMovie(Movie(109));
        user7.addMovie(Movie(108));
        user7.addMovie(Movie(107));
        user7.addMovie(Movie(106));
        user7.addMovie(Movie(105));
        user7.addMovie(Movie(102));
        userDal->addUser(user7);
        
        User user8(8);
        user8.addMovie(Movie(114));
        user8.addMovie(Movie(111));
        user8.addMovie(Movie(109));
        user8.addMovie(Movie(106));
        user8.addMovie(Movie(105));
        user8.addMovie(Movie(104));
        user8.addMovie(Movie(101));
        userDal->addUser(user8);
        
        User user9(9);
        user9.addMovie(Movie(115));
        user9.addMovie(Movie(113));
        user9.addMovie(Movie(112));
        user9.addMovie(Movie(107));
        user9.addMovie(Movie(105));
        user9.addMovie(Movie(103));
        user9.addMovie(Movie(100));
        userDal->addUser(user9);
        
        User user10(10);
        user10.addMovie(Movie(116));
        user10.addMovie(Movie(110));
        user10.addMovie(Movie(109));
        user10.addMovie(Movie(107));
        user10.addMovie(Movie(106));
        user10.addMovie(Movie(105));
        user10.addMovie(Movie(102));
        user10.addMovie(Movie(100));
        userDal->addUser(user10);
        
        // Initialize recommend command with DAL objects
        recommend = new Recommend(movieDal, userDal);
        
        // Redirect cout to our stringstream for testing
        std::cout.rdbuf(output.rdbuf());
    }

    void TearDown() override {
        // Reset cout to its original buffer
        std::cout.rdbuf(nullptr);
        
        // Cleanup
        delete recommend;
        delete movieDal;
        delete userDal;
    }
};

TEST_F(RecommendTest, User1Movie104) {
    // Act
    recommend->execute("1 104");
    
    // Assert
    EXPECT_EQ(output.str(), "105 106 111 110 112 113 107 108 109 114 \n");
}

TEST_F(RecommendTest, User2Movie100) {
    // Act
    recommend->execute("2 100");
    
    // Assert
    EXPECT_EQ(output.str(), "105 107 108 109 110 111 112 113 115 116 \n");
}

TEST_F(RecommendTest, InvalidInput) {
    // Act
    recommend->execute("invalid input");
    
    // Assert
    EXPECT_EQ(output.str(), ""); // Should produce no output
}

TEST_F(RecommendTest, InvalidUserID) {
    // Act
    recommend->execute("999 104");
    
    // Assert
    EXPECT_EQ(output.str(), ""); // Should produce no output
}

TEST_F(RecommendTest, InvalidMovieID) {
    // Act
    recommend->execute("1 999");
    
    // Assert
    EXPECT_EQ(output.str(), ""); // Should produce no output
}

TEST_F(RecommendTest, MultipleCommands) {
    // Act & Assert
    recommend->execute("invalid input");
    EXPECT_EQ(output.str(), "");
    output.str(""); // Clear the buffer

    recommend->execute("999 104");    // Invalid user
    EXPECT_EQ(output.str(), "");
    output.str("");

    recommend->execute("1 104");      // Valid input
    EXPECT_EQ(output.str(), "105 106 111 110 112 113 107 108 109 114\n");
    output.str("");

    recommend->execute("1 999");      // Invalid movie
    EXPECT_EQ(output.str(), "");
}
