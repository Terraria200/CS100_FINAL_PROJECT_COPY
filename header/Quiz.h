#include "Question.h"
#include <vector>

class Quiz {
    private:
        unsigned int score;
        std::vector<Question*> questions;    

    public:
        Quiz();
        void addQuestion(Question* question);
        std::vector<Question*> getQuestions();
        std::string inputAnswer;
        void shuffleQuestions();
        ~Quiz();
};