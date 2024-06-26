#include "gtest/gtest.h"
#include "../header/Quiz.h"
#include "../header/True-or-False.h"

// Include the files name in the cmakelists file in the test folder, then include the header file here

// Question class stub
class QuestionStub : public TrueOrFalse {
    public:
        QuestionStub(std::string content, std::string answer, int score) : TrueOrFalse(content, score, true) {}
        bool checkAnswer(std::string answer) {
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

    std::string expected = "What is 1 + 1?";
    std::string actual;
    std::getline(os, actual, '\n');
    EXPECT_EQ(expected, actual);

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
    
    std::string expected = "What is 1 + 1?";
    std::string actual;
    std::getline(os, actual, '\n');
    EXPECT_EQ(expected, actual);

    expected = "What is 2 + 2?";
    std::getline(os, actual, '\n');
    EXPECT_EQ(expected, actual);

    is << "correct";
    is << "correct";

    EXPECT_EQ(4, quiz.getScore());
}

// Test display question
TEST(QuizTest, displayQuestion) {
    Quiz quiz;
    Question* question = new QuestionStub("What is 1 + 1?", "2", 1);
    quiz.addQuestion(question);
    std::stringstream os;

    quiz.displayQuestion(0, os);
    EXPECT_EQ("1. What is 1 + 1?\n", os.str());
}

// Test display questions
TEST(QuizTest, displayQuestions) {
    Quiz quiz;
    Question* question1 = new QuestionStub("What is 1 + 1?", "2", 1);
    Question* question2 = new QuestionStub("What is 2 + 2?", "4", 1);
    quiz.addQuestion(question1);
    quiz.addQuestion(question2);
    std::stringstream os;

    quiz.displayQuestions(os);
    EXPECT_EQ("1. What is 1 + 1?\n2. What is 2 + 2?\n", os.str());
}

// Test edit question
TEST(QuizTest, editQuestion) {
    Quiz quiz;
    Question* question = new QuestionStub("What is 1 + 1?", "2", 1);
    quiz.addQuestion(question);
    Question* newQuestion = new QuestionStub("What is 2 + 2?", "4", 1);
    quiz.editQuestion(0, newQuestion);
    std::stringstream os;

    quiz.displayQuestion(0, os);
    EXPECT_EQ("1. What is 2 + 2?\n", os.str());
}

// Test remove question
TEST(QuizTest, removeQuestion) {
    Quiz quiz;
    Question* question1 = new QuestionStub("What is 1 + 1?", "2", 1);
    Question* question2 = new QuestionStub("What is 2 + 2?", "4", 1);
    quiz.addQuestion(question1);
    quiz.addQuestion(question2);
    quiz.removeQuestion(0);
    std::stringstream os;

    quiz.displayQuestions(os);
    EXPECT_EQ("1. What is 2 + 2?\n", os.str());
}