#include "gtest/gtest.h"
#include "../header/QuizConstructor.h"

// Test JSONToQuiz
TEST(QuizConstructorTest, JSONToQuiz) {
    QuizConstructor quizConstructor;
    Quiz *quiz = quizConstructor.JSONToQuiz("data/quiz.json");
    EXPECT_EQ(1, quiz->getNumQuestions());
    EXPECT_EQ("The sky is blue.", quiz->getQuestions()[0]->getQuestion());
    EXPECT_EQ(10, quiz->getQuestions()[0]->getScore());
    
    delete quiz;
}

// Test quizToJSON
TEST(QuizConstructorTest, quizToJSON) {
    QuizConstructor quizConstructor;
    Quiz *quiz = new Quiz();
    TrueOrFalse *question = new TrueOrFalse("The sky is blue.", 10, true);
    quiz->addQuestion(question);
    quizConstructor.quizToJSON(quiz, "data/quiz.json");
    Quiz *newQuiz = quizConstructor.JSONToQuiz("data/quiz.json");
    EXPECT_EQ(1, newQuiz->getNumQuestions());
    EXPECT_EQ("The sky is blue.", newQuiz->getQuestions()[0]->getQuestion());
    EXPECT_EQ(10, newQuiz->getQuestions()[0]->getScore());
    EXPECT_EQ("true-or-false", newQuiz->getQuestions()[0]->getType());
    EXPECT_EQ(true, dynamic_cast<TrueOrFalse*>(newQuiz->getQuestions()[0])->checkAnswer("true"));

    delete quiz;
    delete newQuiz;
}

// Test createQuiz
TEST(QuizConstructorTest, createEmptyQuiz) {
    QuizConstructor quizConstructor;

    std::stringstream input;
    std::stringstream output;

    input << "0\n";

    Quiz *quiz = quizConstructor.createQuiz(output, input, "Test Quiz");

    EXPECT_EQ(0, quiz->getNumQuestions());

    delete quiz;
}

// Test quiz with a true or false question
TEST(QuizConstructorTest, createQuizWithTrueFalseQuestion) {
    QuizConstructor quizConstructor;

    std::stringstream input;
    std::stringstream output;

    input << "1\ntrue-or-false\nThe sky is blue.\ntrue\n10\n";

    Quiz *quiz = quizConstructor.createQuiz(output, input, "Test Quiz");

    EXPECT_EQ(1, quiz->getNumQuestions());
    EXPECT_EQ("The sky is blue.", quiz->getQuestions()[0]->getQuestion());
    EXPECT_EQ(10, quiz->getQuestions()[0]->getScore());
    EXPECT_EQ("true-or-false", quiz->getQuestions()[0]->getType());
    EXPECT_EQ(true, quiz->getQuestions()[0]->checkAnswer("true"));

    delete quiz;
}

// Test createTrueFalseQuestion
TEST(QuizConstructorTest, createTrueFalseQuestion) {
    QuizConstructor quizConstructor;

    std::stringstream input;
    std::stringstream output;

    input << "The sky is blue.\ntrue\n10\n";

    Question *question = quizConstructor.createTrueFalseQuestion(output, input);

    EXPECT_EQ("The sky is blue.", question->getQuestion());
    EXPECT_EQ(10, question->getScore());
    EXPECT_EQ("true-or-false", question->getType());
    EXPECT_EQ(true, question->checkAnswer("true"));
}