#include "../header/MultiChoice.h"
#include <algorithm>

bool MultiChoice::checkAnswer(std::string answer) {
    return std::stoi(answer) == this->answer + 1;
}

std::string MultiChoice::getAnswer() {
    return options[answer];
}

int MultiChoice::getIntAnswer() {
    return answer;
}

std::string MultiChoice::getType() {
    return "multiple-choice";
}

std::vector<std::string> MultiChoice::getOptions() {
    return options;
}

std::string MultiChoice::getQuestion() {
    std::string returnString = Question::getQuestion();
    returnString += "\n";
    for (int i = 0; i < options.size(); i++) {
        returnString += std::to_string(i + 1) + ". " + options[i] + "\n";
    }
    return returnString;
}

std::string MultiChoice::getQuestionWithoutOptions() {
    return Question::getQuestion();
}