#ifndef QUESTION_HPP
#define QUESTION_HPP

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