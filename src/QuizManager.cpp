#include "../header/QuizManager.h"

void QuizManager::run(ostream& os, istream& is) {
    // Display quizzes
    displayQuizzes(os, is);

    // If there are available quizzes, prompt user for choice of quiz
    if (quizzes.size() > 0) {
        os << "Enter the number of the quiz you would like to take: ";
        int choice;
        is >> choice;
        is.ignore();
        choice--;

        // If the choice is valid, start the quiz
        if (choice >= 0 && choice < quizzes.size()) {
            quizzes[choice].start(os, is);
        }
        else {
            os << "Invalid choice." << endl;
        }
    }
}

void QuizManager::displayQuizzes(ostream& os, istream& is) {
    if (quizzes.size() == 0) {
        os << "No quizzes available." << endl;
        return;
    }

    os << "Quizzes available: " << endl;
    for (int i = 0; i < quizzes.size(); i++) {
        os << i + 1 << ". " << quizzes[i].getTitle() << endl;
    }
}

void QuizManager::addQuiz(string quizName) {
    quizzes.push_back(Quiz(quizName));
}

void QuizManager::removeQuiz(string quizName) {
    for (int i = 0; i < quizzes.size(); i++) {
        if (quizzes[i].getTitle() == quizName) {
            quizzes.erase(quizzes.begin() + i);
            return;
        }
    }
}

void QuizManager::editQuiz(string quizName, char menuChoice, int questionToEdit, char answerToEdit) {
    for (int i = 0; i < quizzes.size(); i++) {
        if (quizzes[i].getTitle() == quizName) {
            QuizConstructor quizConstructor(quizzes[i]);
            // TODO: Implement editQuiz in QuizConstructor
            // quizzes[i] = quizConstructor.editQuiz(cout, cin, Quiz);

            //char menuChoice = 'g'; // Parameter 1
             //int questionToEdit; // Parameter 2
             //char answerToEdit; // Parameter 3

            quizzes[i] = quizConstructor.editQuiz(menuChoice, questionToEdit, answerToEdit, quizConstructor);

            // My shit = make editQuiz function inside of QuizConstructor (make a call to editQuiz()), read input
            return;
        }
    }
}