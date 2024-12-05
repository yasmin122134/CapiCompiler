#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "App.h"
#include "UserDAL.h"
#include "MovieDAL.h"
#include "AddMovie.h"
#include "Recommend.h"
#include "Help.h"

// Test fixture for setting up the App and dependencies
class MovieRecommendationTest : public ::testing::Test {
protected:
    std::unique_ptr<UserDAL> userDAL;
    std::unique_ptr<MovieDAL> movieDAL;
    std::vector<std::unique_ptr<ICommand>> commands;
    std::istringstream input;
    std::ostringstream output;

    void SetUp() override {
        // Initialize DALs
        userDAL = std::make_unique<UserDAL>();
        movieDAL = std::make_unique<MovieDAL>();

        // Initialize commands
        commands.push_back(std::make_unique<AddMovie>(*userDAL));
        commands.push_back(std::make_unique<Recommend>(*userDAL, *movieDAL));
        commands.push_back(std::make_unique<Help>());
    }

    void TearDown() override {
        // Clean up temporary files or mock data if necessary
    }
};

// Test case for the full CLI flow
TEST_F(MovieRecommendationTest, EndToEndFlow) {
    // Simulate input
    std::string inputCommands = 
        "add 1 101 102 103\n"
        "add 2 101 104 105\n"
        "recommend 1 101\n"
        "help\n";

    input.str(inputCommands);

    // Initialize the App
    App app(std::move(commands), std::move(userDAL), std::move(movieDAL), input, output);

    // Run the application (process all input)
    app.run();

    // Validate the output
    std::string expectedOutput = 
        "Movie recommendations for user 1 based on movie 101:\n"
        "[104, 105]\n" // Assuming the recommendation logic
        "add [userid] [movieid1] [movieid2] ...\n"
        "recommend [userid] [movieid]\n"
        "help\n";

    EXPECT_EQ(output.str(), expectedOutput);
}

// Additional test cases for persistence
TEST_F(MovieRecommendationTest, DataPersistence) {
    // Simulate initial input
    std::string initialCommands = "add 1 101 102\n";
    input.str(initialCommands);

    // Initialize and run the app
    App app1(std::move(commands), std::move(userDAL), std::move(movieDAL), input, output);
    app1.run();

    // Simulate restarting the application
    input.str("recommend 1 101\n");
    output.str(""); // Clear previous output

    // Initialize new commands
    commands.push_back(std::make_unique<AddMovie>(*userDAL));
    commands.push_back(std::make_unique<Recommend>(*userDAL, *movieDAL));
    commands.push_back(std::make_unique<Help>());

    // Create a new App instance with the same DALs to simulate persistence
    App app2(std::move(commands), std::move(userDAL), std::move(movieDAL), input, output);
    app2.run();

    // Validate the output (data persisted correctly)
    std::string expectedOutput =
        "Movie recommendations for user 1 based on movie 101:\n"
        "[102]\n";

    EXPECT_EQ(output.str(), expectedOutput);
}
