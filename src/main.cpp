#include <iostream>
#include "../header/Quiz.h"
#include "../header/QuizManager.h"

int main()
{
    QuizManager quiz_list;
    
    char menuInput = 'z';
    do
    {
        std::cout << "The Mind Meld" << std::endl;
        std::cout << "Press 't' to take a quiz, 'u' to upload a quiz from a JSON file, 'v' to view quizzes, 'e' to edit a quiz, or 'q' to quit: ";

        std::cin >> menuInput;

        if (menuInput == 't')
        {
            quiz_list.run(std::cout, std::cin);
        }
        else if (menuInput == 'u')
        {
            
        }
        else if (menuInput == 'v')
        {
            quiz_list.displayQuizzes(cout, cin);
        }
        else if (menuInput == 'e')
        {
            string quiz_name;
            cout << "Which quiz would you like to edit?" << endl;

            cin >> quiz_name;

            quiz_list.editQuiz(quiz_name);
        }
        else if (menuInput == 'q')
        {
            //Do nothing and keep menu input set to q
            std::cout << "Goodbye!" << std::endl;
        }
        else
        {
            menuInput = 'g'; //An input that will keep the loop going.
        }
    } while (menuInput != 'q');

    return 0;
}
