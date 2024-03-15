#include "gtest/gtest.h"
#include "../header/True-or-False.h"

// Include the files name in the cmakelists file in the test folder, then include the header file here

// Test the constructor
TEST(TrueOrFalseTest, checkAnswer) {
    TrueOrFalse q("Is the earth flat?", 10, false);
    EXPECT_EQ(q.checkAnswer("true"), false);
    EXPECT_EQ(q.checkAnswer("false"), true);

    EXPECT_EQ(q.checkAnswer("True"), false);
    EXPECT_EQ(q.checkAnswer("False"), true);
}

// Test the getAnswer method
TEST(TrueOrFalseTest, getAnswer) {
    TrueOrFalse q("Is the earth flat?", 10, false);
    EXPECT_EQ(q.getAnswer(), "False");
}

// Test the getQuestion method
TEST(TrueOrFalseTest, getQuestion) {
    TrueOrFalse q("Is the earth flat?", 10, false);
    EXPECT_EQ(q.getQuestion(), "Is the earth flat?");
}