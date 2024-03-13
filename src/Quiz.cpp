#include "../header/Quiz.h"
#include <cassert>

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

// Display a question
void Quiz::displayQuestion(unsigned i, std::ostream& os) {
    os << i + 1 << ". " << questions[i]->getQuestion() << std::endl;
}

// Display all the questions
void Quiz::displayQuestions(std::ostream& os) {
    for (unsigned i = 0; i < questions.size(); i++) {
        displayQuestion(i, os);
    }
}

// Edit a question
void Quiz::editQuestion(unsigned i, Question* question) {
    // editQuestion should never be called with an index out of range
    assert(i < questions.size() && "Index out of range");

    delete questions[i];
    questions[i] = question;
}

// Remove a question
void Quiz::removeQuestion(unsigned i) {
    // removeQuestion should never be called with an index out of range
    assert(i < questions.size() && "Index out of range");

    delete questions[i];
    questions.erase(questions.begin() + i);
}

// Get the number of questions
int Quiz::getNumQuestions() {
    return questions.size();
}

// Get the questions
std::vector<Question*> Quiz::getQuestions() {
    return questions;
}