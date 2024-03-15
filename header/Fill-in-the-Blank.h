#include "../header/Question.h"

class FillInTheBlank : public Question {
    private:
    std::string answer;

    public:
        FillInTheBlank(std::string content, int score, std::string answer);
        bool checkAnswer(std::string answer);
        std::string getAnswer();
        std::string getType();
};