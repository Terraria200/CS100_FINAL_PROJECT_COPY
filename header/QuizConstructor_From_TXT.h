#include "QuizConstructor.h"

class QuizConstructor_From_TXT : public QuizConstructor
{
    public:
        Quiz* TXTToQuiz(std::string filename);
};