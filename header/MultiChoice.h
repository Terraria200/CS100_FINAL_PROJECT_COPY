#include "../header/Question.h"
#include <vector>

class MultiChoice : public Question {
    private:
        int answer;
        std::vector<std::string> options;
    public:
        MultiChoice(std::string content, int score, std::vector<std::string> options, int answer) : Question(content, score) {
            this->answer = answer;
            this->options = options;
        }
        bool checkAnswer(std::string answer);
        std::string getAnswer();
        int getIntAnswer();
        std::string getType();
        std::vector<std::string> getOptions();
        std::string getQuestion();
        std::string getQuestionWithoutOptions();
};