#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../commands/Add.h"
#include "../commands/Help.h"
#include "../commands/Recommend.h"
#include "../App.h"
#include "../DataAccessLayer.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <gtest/gtest.h>
#include <sstream>
using namespace std;
#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "../App.h"
#include "../commands/Add.h"
#include "../commands/Help.h"
#include "../commands/Recommend.h"
#include "../DataAccessLayer.h"

TEST(App_End_to_end_test, All_tests) {
    DataAccessLayer dal = DataAccessLayer();

    // Create a vector of raw pointers to commands
    std::vector<ICommand*> commands;
    Help* help = new Help();
    commands.push_back(new Add(&dal));
    commands.push_back(new Recommend(&dal));
    commands.push_back(help);
    help->setCommandList(commands);

    // Use ostringstream to capture output instead of std::cout
    std::istringstream input(
        "add 1 100 101 102 103\n"
        "add 2 101 102 104 105 106\n"
        "add 3 100 104 105 107 108\n"
        "add 4 101 105 106 107 109 110\n"
        "add 5 100 102 103 105 108 111\n"
        "add 6 100 103 104 110 111 112 113\n"
        "add 7 102 105 106 107 108 109 110\n"
        "add 8 101 104 105 106 109 111 114\n"
        "add 9 100 103 105 107 112 113 115\n"
        "add 10 100 102 105 106 107 109 110 116\n"
        "invalid command\n"
        "recommend 1 104\n"
        "help\n"
    );
    
    App app(commands, input, std::cout);

    // Redirect cout to a buffer temporarily
    std::streambuf* old_cout = std::cout.rdbuf();
    std::ostringstream output_buffer;
    std::cout.rdbuf(output_buffer.rdbuf());

    // Run the app
    app.run(true);

    // Restore cout
    std::cout.rdbuf(old_cout);

    // Define the expected output
    std::string expected_output =
        "105 106 111 110 112 113 107 108 109 114\n"
        "add [userid] [movieid1] [movieid2] ...\n"
        "recommend [userid] [movieid]\n"
        "help\n";

    // Compare the actual output with the expected output
    ASSERT_EQ(output_buffer.str(), expected_output);

    // Clean up allocated memory
    for (auto cmd : commands) {
        delete cmd;
    }
}
