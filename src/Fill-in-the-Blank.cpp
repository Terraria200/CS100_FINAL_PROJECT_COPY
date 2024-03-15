#include "../header/Fill-in-the-Blank.h"
#include <algorithm>

FillInTheBlank::FillInTheBlank(std::string content, int score, std::string answer) : Question(content, score) {
    this->answer = answer;
}

bool FillInTheBlank::checkAnswer(std::string answer) {
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == getAnswer()) {
        return true;
    }
    else if (answer != getAnswer()) {
        return false;
    }
    else {
        return false;
    }
}

std::string FillInTheBlank::getAnswer() {
    return this->answer;
}

std::string FillInTheBlank::getType() {
    return "fill-in-the-blank";
}

