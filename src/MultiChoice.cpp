#include "../header/MultiChoice.h"
#include <algorithm>

MultiChoice::MultiChoice(std::string content, int score, std::string answer) : Question(content, answer, score) {
    this->answer = answer;
}

bool MultiChoice::checkAnswer(std::string answer) {
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if (answer == getAnswer()) {
        return "true";
    }
    else if (answer != getAnswer()) {
        return "false";
    }
    else {
        return "false";
    }
}

std::string MultiChoice::GetAnswer() {
    return this->answer;
}