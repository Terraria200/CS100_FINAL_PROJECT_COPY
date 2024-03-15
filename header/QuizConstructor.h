// We put header guards at beginning and end of this file to ensure that we only create it if it's not defined
#ifndef QUIZCONSTRUCTOR_HPP
#define QUIZCONSTRUCTOR_HPP

#include<cstdlib>
#include "Quiz.h"
#include "../header/True-or-False.h"
#include "../header/Question.h"
#include "True-or-False.h"
#include "Fill-in-the-Blank.h"
using namespace std;



class QuizConstructor{
    public:
        QuizConstructor();
        Quiz *JSONToQuiz(string filename);
        void quizToJSON(Quiz *quiz, string filename);
        Quiz *createQuiz(ostream &os, istream &is, string title);
        void editQuiz(ostream& os, istream& is, Quiz *quiz);

        Question* createTrueFalseQuestion(ostream &os, istream &is);
        Question* createMultipleChoiceQuestion(ostream &os, istream &is);
        Question* createFillInTheBlankQuestion(ostream &os, istream &is);
};


#endif