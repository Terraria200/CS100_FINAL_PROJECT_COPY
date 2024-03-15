#include <iostream>
#include <stdlib.h>
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
        system("clear");

        std::cout << "\n\tThe Mind Meld" << std::endl;
        std::cout << "Press:"
                    "\n't' to take a quiz"
                    "\n'u' to upload a quiz from a JSON file"
                    "\n'd' to download a quiz to a JSON file"
                    "\n'c' to create a quiz"
                    "\n'v' to view quizzes"
                    "\n'e' to edit a quiz"
                    "\nOR"
                    "\n'q' to quit: ";

        getline(std::cin, menuInput);

        if (menuInput[0] == 't')
        {
            quiz_list.run(std::cout, std::cin);

            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'u')
        {
            std::cout << "\nWhat is the filepath that you would like to have the quiz uploaded from?" << std::endl;
        
            string filepath;
            getline(cin, filepath);

            quiz_list.uploadQuiz(filepath);
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'd')
        {
            std::cout << "\nWhat is the filepath that you would like to have the quiz downloaded to?" << std::endl;

            string filepath;
            getline(cin, filepath);

            quiz_list.downloadQuiz(filepath);
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'c')
        {
            quiz_list.createQuizInhouse(std::cout, std::cin);
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'v')
        {
            quiz_list.displayQuizzes(cout);
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'e')
        {
            quiz_list.editQuiz();
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
        else if (menuInput[0] == 'q')
        {
            std::cout << "\nGoodbye!" << std::endl;
        }
        else
        {
            std::cout << "\nInvalid input" << std::endl;
            
            std::cout << "\nPress ENTER to return to the main menu." << std::endl;
            std::cin.clear();
            std::cin.get();
        }
    } while (menuInput[0] != 'q');

    return 0;
}
