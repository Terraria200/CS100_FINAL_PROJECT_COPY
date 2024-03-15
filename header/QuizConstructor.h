// We put header guards at beginning and end of this file to ensure that we only create it if it's not defined
#ifndef QUIZCONSTRUCTOR_HPP
#define QUIZCONSTRUCTOR_HPP

#include<cstdlib>
#include "Quiz.h"
//#include "True-or-False.h"
#include "../header/Question.h"
using namespace std;



class QuizConstructor{
    private: // Pretty sure that generally, variables are private while functions are public
        Quiz *quiz;
    public:
        QuizConstructor();
        QuizConstructor(Quiz *quiz);
        Quiz *JsonToQuiz(string filename);
        void setAnswer();
        void editQuestion(ostream& os, istream& is, char menuChoice, int questionToEdit, char answerToEdit, Quiz& quiz);

        void editQuiz(char menuChoice, int questionToEdit, char answerToEdit, QuizConstructor quizConstructor);

        Question* createTrueFalseQuestion(ostream &os, istream &is);
        Question* createMultipleChoiceQuestion(ostream &os, istream &is);
        Question* createFillInTheBlankQuestion(ostream &os, istream &is);
};


#endif