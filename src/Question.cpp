#include "../header/Question.h"

Question::Question() {
    this->content = "";
}

Question::Question(std::string content, int score) {
    this->content = content;
    this->score = score;
}

std::string Question::getQuestion() {
    return this->content;
}

void Question::setQuestion(std::string content) {
    this->content = content;
}

void Question::setScore(int score) {
    this->score = score;
}

int Question::getScore() {
    return this->score;
}