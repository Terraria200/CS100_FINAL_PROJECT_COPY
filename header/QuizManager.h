#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "Quiz.h"
#include "QuizConstructor.h"
#include <vector>

class QuizManager {
    private:
        vector<Quiz*> quizzes;
    public:
        void run(ostream& os, istream& is);
        void displayQuizzes(ostream& os);
        void addQuiz(string quizName);
        void removeQuiz(string quizName);
        void editQuiz();
        void uploadQuiz(string filepath);
        void downloadQuiz(string filepath);
        void createQuizInhouse(ostream &os, istream &is);
};

#endif
