#include "gtest/gtest.h"
#include "../header/Fill-in-the-Blank.h"

// Include the files name in the cmakelists file in the test folder, then include the header file here

// Test the constructor
TEST(FillInTheBlankTest, checkAnswer) {
    FillInTheBlank q("Did we go to space?", 10, "true");
    EXPECT_EQ(q.checkAnswer("true"), "true");
    EXPECT_EQ(q.checkAnswer("true"), "false");
}

// Test the getAnswer method
TEST(FillInTheBlankTest, getAnswer) {
    FillInTheBlank q("Did we go to space?", 10, "false");
    EXPECT_EQ(q.getAnswer(), "False");
}

// Test the getQuestion method
TEST(FillInTheBlankTest, getQuestion) {
    FillInTheBlank q("Did we go to space?", 10, "true");
    EXPECT_EQ(q.getQuestion(), "Did we go to space?");
}