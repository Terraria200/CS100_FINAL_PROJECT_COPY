#include <iostream>
#include "../header/Quiz.h"
#include "../header/True-or-False.h"
#include "../header/Question.h" // Add the missing include directive

int main() {
    // Create a new quiz object
    Quiz quizObject;

    // Create a new question object
    Question* q1 = new TrueOrFalse("Is the sky blue?", 10, true);

    // Add the question to the quiz
    quizObject.addQuestion(q1);

    // Start the quiz
    quizObject.start(std::cout, std::cin);

    return 0;
}
