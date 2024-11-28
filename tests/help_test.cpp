#include <gtest/gtest.h>
#include "Help.h"

TEST(HelpTest, GetCommandList) {
    Help help;
    std::string expected_output = "add [userid] [movieid1] [movieid2] ...\n"
                                 "recommend [userid] [movieid]\n"
                                 "help";
    
    EXPECT_EQ(help.getCommandList(), expected_output);
}
