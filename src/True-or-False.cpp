#include "../header/True-or-False.h"
#include <algorithm>

TrueOrFalse::TrueOrFalse(std::string content, int score, bool answer) : Question(content, score) {
    this->answer = answer;
}

bool TrueOrFalse::checkAnswer(std::string answer) {
    // Convert to lowercase
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == "true") {
        return this->answer;
    } else if (answer == "false") {
        return !this->answer;
    } else {
        return false;
    }
}

std::string TrueOrFalse::getAnswer() {
    return this->answer ? "True" : "False";
}

bool TrueOrFalse::getBoolAnswer() {
    return this->answer;
}

std::string TrueOrFalse::getType() {
    return "true-or-false";
}