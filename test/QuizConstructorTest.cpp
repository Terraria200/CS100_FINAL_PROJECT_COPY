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