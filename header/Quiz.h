// We put header guards at beginning and end of this file to ensure that we only create it if it's not defined
#ifndef QUIZ_H
#define QUIZ_H

#include<cstdlib>
using namespace std;

class Quiz{
    private:
        vector <Question*> questions; // The list of questions in the quiz
        unsigned int score; // The user's current score; updated based on if answer choice is correct or incorrect
        string inputAnswer; // The user's chosen answer
    public:
        void shuffleQuestions(); // Switch around the order of questions in the vector
}



#endif