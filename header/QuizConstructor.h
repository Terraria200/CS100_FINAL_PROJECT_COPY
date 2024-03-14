// We put header guards at beginning and end of this file to ensure that we only create it if it's not defined
#ifndef QUIZCONSTRUCTOR_HPP
#define QUIZCONSTRUCTOR_HPP

#include<cstdlib>
#include "Quiz.h"
#include "True-or-False.h"
using namespace std;

class QuizConstructor{
    private: // Pretty sure that generally, variables are private while functions are public
        Quiz *quiz;
    public:
        QuizConstructor();
        Quiz *JSONToQuiz(string filename);
        void quizToJSON(Quiz *quiz, string filename);
        void setAnswer();
        void editQuestion();

        Question* createTrueFalseQuestion(ostream &os, istream &is);
        Question* createMultipleChoiceQuestion(ostream &os, istream &is);
        Question* createFillInTheBlankQuestion(ostream &os, istream &is);
};


#endif