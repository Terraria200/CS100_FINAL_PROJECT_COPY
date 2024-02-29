#include "gtest/gtest.h"
#include "../header/Quiz.h"

// Include the files name in the cmakelists file in the test folder, then include the header file here

// Question class stub
class QuestionStub : public Question {
    public:
        QuestionStub(std::string content, std::string answer, int score) : Question(content, answer, score) {}
        bool checkAnswer(std::string answer) {
            if (answer.compare("correct") != 0) {
                return false;
            }
            return true;
        }
};

// Test the constructor
TEST(QuizTest, constructor) {
    Quiz quiz;
    EXPECT_EQ(0, quiz.getScore());
}

// Test the addQuestion method
TEST(QuizTest, addQuestion) {
    Quiz quiz;
    Question* question = new QuestionStub("What is 1 + 1?", "2", 1);
    ASSERT_NO_THROW(quiz.addQuestion(question));
}

// Test the start method
TEST(QuizTest, start) {
    Quiz quiz;
    Question* question = new QuestionStub("What is 1 + 1?", "2", 1);
    quiz.addQuestion(question);
    std::stringstream os;
    std::stringstream is;

    quiz.start(os, is);
    EXPECT_EQ("What is 1 + 1?\n", os.str());

    is << "correct";
    EXPECT_EQ(1, quiz.getScore());
}

// Test multiple questions
TEST(QuizTest, multipleQuestions) {
    Quiz quiz;
    Question* question1 = new QuestionStub("What is 1 + 1?", "2", 1);
    Question* question2 = new QuestionStub("What is 2 + 2?", "4", 3);
    quiz.addQuestion(question1);
    quiz.addQuestion(question2);
    std::stringstream os;
    std::stringstream is;

    quiz.start(os, is);
    EXPECT_EQ("What is 1 + 1?\n", os.str());

    is << "correct";
    EXPECT_EQ(1, quiz.getScore());

    EXPECT_EQ("What is 1 + 1?\nWhat is 2 + 2?\n", os.str());

    is << "correct";
    EXPECT_EQ(4, quiz.getScore());
}
