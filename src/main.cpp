#include <iostream>
#include "../header/Quiz.h"

int main()
{
    char menuInput = 'z';
    do
    {
        
        std::cout << "The Mind Meld" << std::endl;
        std::cout << "Press 't' to take a quiz, 'u' to upload a quiz, 'e' to edit a quiz, or 'q' to quit: ";

        std::cin >> menuInput;

        if (menuInput == 't')
        {

        }
        else if (menuInput == 'u')
        {

        }
        else if (menuInput == 'e')
        {

        }
        else if (menuInput == 'q')
        {
            //Do nothing and keep menu input set to q
        }
        else
        {
            menuInput = 'g'; //An input that will keep the loop going.
        }
    } while (menuInput != 'q');

    return 0;
}