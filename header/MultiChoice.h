#include "../header/Question.h"

class MultiChoice : public Question {
    private:
        std::string answer;
    public:
        MultiChoice(std::string content, int score, std::string answer);
        bool checkAnswer(std::string answer);
        std::string GetAnswer();
        std::string getType();
};