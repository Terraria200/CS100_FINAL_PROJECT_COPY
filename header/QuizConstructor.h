// We put header guards at beginning and end of this file to ensure that we only create it if it's not defined
#ifndef QUIZCONSTRUCTOR_HPP
#define QUIZCONSTRUCTOR_HPP

#include<cstdlib>
using namespace std;

class QuizConstructor{
    private: // Pretty sure that generally, variables are private while functions are public
        Quiz *quiz;
    public:
        QuizConstructor();
        Quiz *JsonToQuiz(string filename);
        void setAnswer();
        void editQuestion();
}


#endif