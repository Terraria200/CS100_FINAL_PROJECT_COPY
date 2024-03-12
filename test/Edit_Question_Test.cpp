#include "gtest/gtest.h"
#include "../header/QuizConstructor.h"

TEST(EditQuestionTest, editQuestion){
    // It MIGHT be a good idea to switch the editing Question function to have less cin statements
    EXPECT_TRUE(this->QuizConstructor->editQuestion() == 0);
}

