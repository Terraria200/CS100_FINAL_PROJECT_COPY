#include "../header/Question.h"

class TrueOrFalse : public Question {
private:
    bool answer;
public:
    TrueOrFalse(std::string content, int score, bool answer);
    bool checkAnswer(std::string answer);
    std::string getAnswer();
};