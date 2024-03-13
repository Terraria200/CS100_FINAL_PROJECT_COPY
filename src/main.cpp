#include <iostream>

int main()
{
    std::ostream output;
    std::istream input;

    output << "The Mind Meld" << std::endl;
    output << "Press 't' to take a quiz, 'u' to upload a quiz, 'e' to edit a quiz, or 'q' to quit: ";

    char menuInput = 'z';
    input >> menuInput;
    while (menuInput != 'q')
    {
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

        }
        else
        {
            menuInput = 'g'; //An input that will keep the loop going.
        }

        output << "The Mind Meld" << std::endl;
        output << "Press 't' to take a quiz, 'u' to upload a quiz, 'e' to edit a quiz, or 'q' to quit: ";
    }
}