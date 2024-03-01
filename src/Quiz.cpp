#include "../header/Quiz.h"

Quiz::Quiz() {
    this->score = 0;
}

void Quiz::shuffleQuestions() {
    
}

void Quiz::addQuestion(Question* question) {
        questions.push_back(question);
}

std::vector<Question*> Quiz::getQuestions() {
    return questions;
}