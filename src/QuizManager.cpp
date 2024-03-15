#include "../header/QuizManager.h"

void QuizManager::run(ostream& os, istream& is) {
    // Display quizzes
    displayQuizzes(os);

    // If there are available quizzes, prompt user for choice of quiz
    if (quizzes.size() > 0) {
        os << "\nEnter the number of the quiz you would like to take: ";
        int choice;
        is >> choice;
        is.ignore();
        choice--;

        // If the choice is valid, start the quiz
        if (choice >= 0 && choice < static_cast<int>(quizzes.size())) {
            quizzes[choice]->start(os, is);
        }
        else {
            os << "Invalid choice." << endl;
        }
    }
}

void QuizManager::displayQuizzes(ostream& os) {
    if (quizzes.size() == 0) {
        os << "\nNo quizzes available." << endl;
        return;
    }

    os << "\nQuizzes available: " << endl;
    for (int i = 0; i < static_cast<int>(quizzes.size()); i++) {
        os << i + 1 << ". " << quizzes[i]->getTitle() << endl;
    }
}

void QuizManager::addQuiz(string quizName) {
    quizzes.push_back(new Quiz(quizName));
}

void QuizManager::removeQuiz(string quizName) {
    if (quizzes.size() == 0)
    {
        std::cout << "\nThere are no quizzes to remove." << std::endl;
        return;
    }
    
    for (auto it = quizzes.begin(); it != quizzes.end(); ) {
        if ((*it)->getTitle() == quizName) {
            it = quizzes.erase(it);
            return;
        } else {
            ++it;
        }
    }
    // Quiz not found
    throw std::invalid_argument("Quiz not found");
}

void QuizManager::editQuiz() {

    if (quizzes.size() == 0)
    {
        std::cout << "\nThere are no quizzes to edit." << std::endl;
        return;
    }
            
    std::cout << "\nWhich quiz would you like to edit?" << endl;

    string quizName;
    std::cin >> quizName;

    for (auto* quiz : quizzes) {
    if (quiz->getTitle() == quizName) {
        QuizConstructor quizConstructor;
        quizConstructor.editQuiz(std::cout, std::cin, quiz);
        return;
    }
}

    //Quiz not found
    cout << "\nThat quiz does not exist." << endl;
}

void QuizManager::uploadQuiz(string filepath)
{
    Quiz* uploaded_quiz;
    QuizConstructor uploader;

    if ((uploaded_quiz = uploader.JSONToQuiz(filepath)))
    {
        quizzes.push_back(uploaded_quiz);
        std::cout << "\nQuiz successfully uploaded." << std::endl;
    }
    else
    {
        std::cout << "\nThe file was not able to be opened." << std::endl;
    }
}

void QuizManager::downloadQuiz(string filepath)
{
    if (static_cast<int>(quizzes.size()) == 0)
    {
        std::cout << "\nThere are no quizzes to download." << std::endl;
        return;
    }


    std::cout << "\nWhich quiz would you like to download?" << std::endl;
    string quizName;
    getline(std::cin, quizName);

    for (int i = 0; i < static_cast<int>(quizzes.size()); i++) {
        if (quizzes[i]->getTitle() == quizName) {
            QuizConstructor JSONdownloader;

            JSONdownloader.quizToJSON(quizzes[i], filepath);
            std::cout << "\nQuiz donwloaded" << std::endl;

             return;
        }
    }

    std::cout << "\nThat quiz does not exist. Exiting to main menu." << std::endl;
}

void QuizManager::createQuizInhouse(ostream &os, istream &is)
{
    Quiz *new_quiz;
    QuizConstructor constructor;

    os << "\nWhat would you like the quiz to be named?" << std::endl;
    string quiz_title;
    is >> quiz_title;

    new_quiz = constructor.createQuiz(os, is, quiz_title);

    this->quizzes.push_back(new_quiz);
}