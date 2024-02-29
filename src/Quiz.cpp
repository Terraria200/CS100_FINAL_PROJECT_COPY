#include "../header/Quiz.h"

// Constructor
Quiz::Quiz() {
    score = 0;
}

// Destructor
Quiz::~Quiz() {
    clear();
}

// Add a question to the quiz
void Quiz::addQuestion(Question* question) {
    questions.push_back(question);
}

// Get the score
unsigned Quiz::getScore() {
    return score;
}

// Start the quiz
void Quiz::start(std::ostream& os, std::istream& is) {
    // For each question, ask the question and check the answer
    for (auto question : questions) {
        os << question->getQuestion() << std::endl;

        std::string answer;
        is >> answer;
        
        if (question->checkAnswer(answer)) {
            score += question->getScore();
        }

        // Clear the input buffer
        is.clear();
    }
}

// Clear the questions
void Quiz::clear() {
    for (auto question : questions) {
        delete question;
    }
    questions.clear();
}