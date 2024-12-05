#include <gtest/gtest.h>
#include "../commands/Help.h"
#include "../commands/Add.h"
#include "../commands/Recommend.h"
#include "../DataAccessLayerFile.h"
#include <sstream>

TEST(HelpTest, GetCommandList) {
    DataAccessLayerFile dal = DataAccessLayerFile();
    std::vector<ICommand*> commands;
    Help* help = new Help();
    commands.push_back(new Add(&dal));
    commands.push_back(new Recommend(&dal));
    commands.push_back(help);
    help->setCommandList(commands);
    std::string expected_output = "add [userid] [movieid1] [movieid2] ...\n"
                                 "recommend [userid] [movieid]\n"
                                 "help\n";
    
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf()); // Redirect cout to oss

    help->execute("");

    std::cout.rdbuf(oldCoutBuf); // Restore original cout buffer

    std::string output = oss.str();
    EXPECT_EQ(output, expected_output);
}
