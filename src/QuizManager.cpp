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
            quizzes[choice]->start(os, is);
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
        os << i + 1 << ". " << quizzes[i]->getTitle() << endl;
    }
}

void QuizManager::addQuiz(string quizName) {
    quizzes.push_back(new Quiz(quizName));
}

void QuizManager::removeQuiz(string quizName) {
    if (quizzes.size() == 0)
    {
        std::cout << "There are no quizzes to remove." << std::endl;
        return;
    }
    
    for (int i = 0; i < quizzes.size(); i++) {
        if (quizzes[i]->getTitle() == quizName) {
            quizzes.erase(quizzes.begin() + i);
            return;
        }
    }
}

void QuizManager::editQuiz() {

    if (quizzes.size() == 0)
    {
        std::cout << "There are no quizzes to edit." << std::endl;
        return;
    }
            
    std::cout << "Which quiz would you like to edit?" << endl;

    string quizName;
    std::cin >> quizName;

    for (int i = 0; i < quizzes.size(); i++) {
        if (quizzes[i]->getTitle() == quizName) {
            QuizConstructor quizConstructor;
            // TODO: Implement editQuiz in QuizConstructor
            // quizzes[i] = quizConstructor.editQuiz(cout, cin);
            return;
        }
    }

    //Quiz not found
    cout << "That quiz does not exist." << endl;
}

void QuizManager::uploadQuiz(string filepath)
{
    Quiz* uploaded_quiz;
    QuizConstructor uploader;

    if (uploaded_quiz = uploader.JSONToQuiz(filepath))
    {
        quizzes.push_back(uploaded_quiz);
        std::cout << "Quiz successfully uploaded." << std::endl;
    }
    else
    {
        std::cout << "The file was not able to be opened." << std::endl;
    }
}

void QuizManager::downloadQuiz(string filepath)
{
    if (quizzes.size() == 0)
    {
        std::cout << "There are no quizzes to download." << std::endl;
        return;
    }


    std::cout << "Which quiz would you like to download?" << std::endl;
    string quizName;
    getline(std::cin, quizName);

    for (int i = 0; i < quizzes.size(); i++) {
        if (quizzes[i]->getTitle() == quizName) {
            QuizConstructor JSONdownloader;

            JSONdownloader.quizToJSON(quizzes[i], filepath);
            std::cout << "Quiz donwloaded" << std::endl;

             return;
        }
    }

    std::cout << "That quiz does not exist. Exiting to main menu." << std::endl;
}

void QuizManager::createQuizInhouse(ostream &os, istream &is)
{
    Quiz *new_quiz;
    QuizConstructor constructor;

    os << "What would you like the quiz to be named?" << std::endl;
    string quiz_title;
    is >> quiz_title;

    new_quiz = constructor.createQuiz(os, is, quiz_title);

    this->quizzes.push_back(new_quiz);
}