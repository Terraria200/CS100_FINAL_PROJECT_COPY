#include "../header/Question.h"

Question::Question() {
    this->content = "";
    this->answer = "";
}

Question::Question(std::string content, std::string answer, int score) {
    this->content = content;
    this->answer = answer;
    this->score = score;
}

std::string Question::getQuestion() {
    return this->content;
}

std::string Question::getAnswer() {
    return this->answer;
}

void Question::setQuestion(std::string content) {
    this->content = content;
}

void Question::setAnswer(std::string answer) {
    this->answer = answer;
}

void Question::setScore(int score) {
    this->score = score;
}

int Question::getScore() {
    return this->score;
}