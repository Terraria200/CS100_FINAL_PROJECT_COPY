#include "../header/Quiz.h"
#include <cassert>
#include <chrono>
#include <iomanip>
#include <sstream>

// Default constructor
Quiz::Quiz() {
    this->title = "Untitled Quiz";
    score = 0;
}

// Constructor
Quiz::Quiz(std::string title) {
    this->title = title;
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
    int questionsCorrect = 0;
    int questionsAnswered = 0;
    score = 0;

    //Start of timer
    auto start = std::chrono::high_resolution_clock::now();

    // For each question, ask the question and check the answer
    for (auto question : questions) {
        os << question->getQuestion() << std::endl;

        std::string answer;
        is >> answer;
        
        if (question->checkAnswer(answer)) {
            score += question->getScore();
            questionsCorrect++;
        }

        questionsAnswered++;

        // Clear the input buffer
        is.clear();
    }

    //End of timer
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> quiz_time = finish - start;

    //Stats screen
    double correctPercentage = (static_cast<double>(questionsCorrect) / static_cast<double>(questionsAnswered)) * 100;

    std::stringstream time;

    os << "\n" << "QUIZ STATISTICS:" << std::endl;

    os << "SCORE: " << score << std::endl;

    os << "QUESTIONS CORRECT: " << questionsCorrect << "/" << questionsAnswered << std::endl;

    os << "% CORRECT: " << correctPercentage << "%" << std::endl;

    //Time output in format HOURS:MINUTES:SECONDS

    time << static_cast<int>(quiz_time.count() / 3600);
    time << ":";
    time << std::setfill('0') << std::setw(2) << static_cast<int>(quiz_time.count() / 60);
    time << ":";
    time << std::setfill('0') << std::setw(2) << static_cast<int>(quiz_time.count()) % 60;

    os << "TIME TAKEN: " << time.str() << std::endl;

    // Wait for the user to press enter
    std::string enterKeyPress;
    std::getline(is, enterKeyPress);
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

// Get the title
std::string Quiz::getTitle() {
    return title;
}

// Set the title
void Quiz::setTitle(std::string title) {
    this->title = title;
}