#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include <iostream>
#include "../header/Question.h"

class Quiz {
private:
    std::vector<Question*> questions;
    unsigned score;
public:
    Quiz();
    std::vector<Question*> getQuestions();
    void addQuestion(Question* question);
    void removeQuestion(unsigned index);
    int getNumQuestions();
    void displayQuestions(std::ostream& os);
    void displayQuestion(unsigned index, std::ostream& os);
    void editQuestion(unsigned index, Question* question);
    void start(std::ostream& os, std::istream& is);
    unsigned getScore();
    void reset();
    void clear();
    ~Quiz();
};

#endif