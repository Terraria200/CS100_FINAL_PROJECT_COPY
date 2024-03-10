#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include<cstdlib>
using namespace std;

class Question{
    private:
        string content; // The question itself
        string correctAnswer; 
    public:
        boolean checkAnswer();
        void changeScore();
        void setAnswer();
        //void editQuestion();
}

#endif