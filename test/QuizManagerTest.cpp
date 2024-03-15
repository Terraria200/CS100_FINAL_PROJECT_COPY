#include "../header/QuizManager.h"
#include "gtest/gtest.h"

// Create a fixture with a Quizmanager object containing various quizzes
class QuizManagerTest : public ::testing::Test {
protected:
    QuizManager quizManager;
    void SetUp() override {
        quizManager.addQuiz("quiz1");
        quizManager.addQuiz("quiz2");
        quizManager.addQuiz("quiz3");
    }
};

TEST(QuizManagerTest, emptyRun) {
    QuizManager quizManager;
    std::stringstream input;
    std::stringstream output;
    quizManager.run(output, input);
    std::string expected = "\nNo quizzes available.\n";
    ASSERT_EQ(expected, output.str());
}

