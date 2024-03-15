#include "gtest/gtest.h"
#include "../header/MultiChoice.h"

// Include the files name in the cmakelists file in the test folder, then include the header file here

// Test the constructor
TEST(MultiChoiceTest, checkAnswer) {
    MultiChoice q("Did we go to space?", 10, "true");
    EXPECT_EQ(q.checkAnswer("true"), "true");
    EXPECT_EQ(q.checkAnswer("true"), "false");
}

// Test the getAnswer method
TEST(MultiChoiceTest, getAnswer) {
    MultiChoice q("Did we go to space?", 10, "false");
    EXPECT_EQ(q.getAnswer(), "False");
}

// Test the getQuestion method
TEST(MultiChoiceTest, getQuestion) {
    MultiChoice q("Did we go to space?", 10, "true");
    EXPECT_EQ(q.getQuestion(), "Did we go to space?");
}