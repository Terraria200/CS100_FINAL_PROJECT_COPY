#include <string>
class Question {
    private:
        std::string content;
        std::string answer;
        int score;
    public:
        Question();
        Question(std::string content, std::string answer, int score);
        virtual std::string getQuestion();
        virtual std::string getAnswer();
        virtual void setQuestion(std::string content);
        virtual void setAnswer(std::string answer);
        void setScore(int score);
        int getScore();
        virtual bool checkAnswer(std::string answer) = 0;
};