#include "../header/Quiz.h"
#include "../header/QuizConstructor.h"
#include "../header/QuizManager.h"
#include <iostream>

int main() {
    QuizManager quizManager;
    quizManager.run(std::cout, std::cin);
    return 0;
}
