#include "gtest/gtest.h"
#include "../header/QuizConstructor_From_TXT.h"
#include <fstream>
#include <string>

class QuizConstructor_TXT_Stub : public QuizConstructor
{
    public:
        Quiz* TXTToQuiz(std::string quizfile)
        {
            std::ifstream input_file;

            Quiz* new_quiz;

            input_file.open(quizfile);

            if (input_file.is_open())
            {
                std::string input_question;
                while(getline(input_file, input_question))
                {
                    Question* new_question;

                    new_question->setQuestion(input_question);

                    std::string input_answer;
                    getline(input_file, input_answer);
                    new_question->setAnswer(input_answer);

                    int input_score;
                    if (input_file >> input_score)
                    {
                        new_question->setScore(input_score);
                    }

                    new_quiz->addQuestion(new_question);

                    //Reset the inputs
                    input_question = "";
                    input_answer = "";
                    input_score = 0;
                }
            }

            return new_quiz;

        }
};

TEST(Upload_from_TXT, testQuestionShort)
{
    std::string quizfile = "QUIZ.txt";

    QuizConstructor_TXT_Stub constructor;

    Quiz* quiz = constructor.TXTToQuiz(quizfile);

    ASSERT_EQ("What is a banana?", quiz->getQuestions()[1]->getQuestion());
}

TEST(Upload_from_TXT, testQuestionLonger)
{
    std::string quizfile = "QUIZ.txt";

    QuizConstructor_TXT_Stub constructor;

    Quiz* quiz = constructor.TXTToQuiz(quizfile);

    ASSERT_EQ("Which Civil War general did President Abraham Lincoln invite to the theater where the President would later be assassinated?", quiz->getQuestions()[3]->getQuestion());
}

TEST(Upload_from_TXT, testAnswer)
{
    std::string quizfile = "QUIZ.txt";

    QuizConstructor_TXT_Stub constructor;

    Quiz* quiz = constructor.TXTToQuiz(quizfile);

    ASSERT_EQ("Ulysses S. Grant", quiz->getQuestions()[3]->getAnswer());
}