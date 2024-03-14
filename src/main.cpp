#include <iostream>
#include "../header/Quiz.h"
#include "../header/QuizManager.h"
#include "../header/QuizConstructor.h"

int main()
{
    QuizManager quiz_list;
    QuizConstructor constructor;
    
    string menuInput = "z";
    do
    {
        std::cout << "The Mind Meld" << std::endl;
        std::cout << "Press 't' to take a quiz, 'u' to upload a quiz from a JSON file, 'd' to download a quiz to a JSON file, 'c' to create a quiz, 'v' to view quizzes, 'e' to edit a quiz, or 'q' to quit: ";

        getline(std::cin, menuInput);

        if (menuInput[0] == 't')
        {
            quiz_list.run(std::cout, std::cin);
        }
        else if (menuInput[0] == 'u')
        {
            
        }
        else if (menuInput[0] == 'd')
        {
            
        }
        else if (menuInput[0] == 'c')
        {
            // std::cout << "What would you like the name of the quiz to be?" << std::endl;
            
            // string quiz_title;
            // cin >> quiz_title;

            // constructor.createQuiz(cout, cin, quiz_title);
        }
        else if (menuInput[0] == 'v')
        {
            quiz_list.displayQuizzes(cout, cin);
        }
        else if (menuInput[0] == 'e')
        {
            string quiz_name;
            cout << "Which quiz would you like to edit?" << endl;

            cin >> quiz_name;

            quiz_list.editQuiz(quiz_name);
        }
        else if (menuInput[0] == 'q')
        {
            //Do nothing and keep menu input set to q
            std::cout << "Goodbye!" << std::endl;
        }
        else
        {
            menuInput = 'g'; //An input that will keep the loop going.
        }
    } while (menuInput[0] != 'q');

    return 0;
}
