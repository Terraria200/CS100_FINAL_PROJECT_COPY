#include "QuizConstructor.h"
#include <fstream>

Quiz* TXTtoQuiz(std::string quizfile)
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