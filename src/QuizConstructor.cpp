#include "QuizConstructor.h"

QuizConstructor::QuizConstructor(){
}

Quiz * QuizConstructor::JsonToQuiz(string filename){
    // Return quiz object
    return quiz;
}

void QuizConstructor::setAnswer(){
    string correctAnswer;
    getline(cin, correctAnswer, '\n');
}

void QuizConstructor::editQuestion(){
    int questionToEdit;
    char menuChoice = 'g';
    char answerToEdit;
    while(menuChoice != 'q'){
        cout << "Select a question to edit from 1- " << quiz->getNumQuestions() << ": ";
        cin >> questionToEdit;
        cout << endl;
        while(menuChoice != 'm'){
            if(questionToEdit >= 1 && questionToEdit <= quiz->getNumQuestions()){
                cout << "Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
                cin >> menuChoice;
                cout << endl;
                if(menuChoice == 'q'){
                    cout << "Old question is \"";
                    quiz->displayQuestion(questionToEdit, cout);
                    cout << "\" Enter the new or edited question: ";

                    // TEMPORARY FIX: only TrueOrFalse questions are supported at the moment
                    string newQuestion;
                    getline(cin, newQuestion);
                    quiz->editQuestion(questionToEdit, new TrueOrFalse(newQuestion, 1, true));

                    cout << endl;
                    cout << "Changes saved! Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
                }
                else if(menuChoice == 'a'){
                    cout << "Which options would you like to edit? Press 'q' when ready to quit editing" << endl;

                    char alphabet = 'a';
                    
                    // ENDLESS LOOP
                    // while(menuChoice != 'q'){
                    //     for(unsigned int i = 0; i < options.size(); ++i){
                    //         cin >> answerToEdit;
                    //         cout << alphabet << ". " << options[i] << endl;
                    //         if(answerToEdit == alphabet){
                    //             cout << "What would you like to change it too? ";
                    //             getline(cin, options[i]);
                    //             cout << "Changes saved! Which options would you like to edit? Press 'q' when ready to quit editing" << endl;
                    //         }
                    //     ++alphabet;
                    //     }
                    // }
                }
                else if(menuChoice == 'm'){
                    menuChoice = 'q'; // Quit out of the editing process
                }
                else {
                    menuChoice == 'b'; // Not a valid question number, so try edit process again
                }
            }
            else{
                menuChoice= 'b'; // Not a valid question number, so try edit process again
            }
        }
    }
}