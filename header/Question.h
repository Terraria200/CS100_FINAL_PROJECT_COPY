#include <string>
class Question {
    private:
        std::string content;
        int score;
    public:
        Question();
        Question(std::string content, int score);
        virtual std::string getQuestion();
        virtual std::string getAnswer() = 0;
        virtual void setQuestion(std::string content);
        void setScore(int score);
        int getScore();
        virtual bool checkAnswer(std::string answer) = 0;
};