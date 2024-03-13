#include "../header/QuizConstructor.h"
#include <gtest/gtest.h>

QuizConstuctor::QuizConstructor(){
}

Quiz * QuizConstructor::JsonToQuiz(string filename){
}

void QuizConstructor::setAnswer(){
    getline(cin, correctAnswer);
}

int QuizConstructor::editQuestion(){ // 0 means successfully reached end, 1 means didn't successfully reach end
    int r = 1;
    int questionToEdit;
    char menuChoice = 'g';
    char answerToEdit;
    while(menuChoice != 'q'){
        cout << "Select a question to edit from 1- " << questions.size() << ": ";
        cin >> questionToEdit;
        cout << endl;
        while(menuChoice != 'm'){
            if(questionToEdit >= 1 && questionToEdit <= questions.size()){
                cout << "Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
                cin >> menuChoice;
                cout << endl;
                if(menuChoice == 'q'){
                    cout << "Old question is \"" << questions[questionToEdit]->content << "\" Enter the new or edited question: "
                    getline(cin, questions[questionToEdit]->content);
                    cout << endl;
                    cout << "Changes saved! Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
                }
                else if(menuChoice == 'a'){
                    cout << "Which options would you like to edit? Press 'q' when ready to quit editing" << endl;

                    char alphabet = 'a';
                    while(menuChoice != 'q'){
                        for(unsigned int i = 0; i < options.size(); ++i){
                            cin >> answerToEdit;
                            cout << alphabet << ". " << options[i] << endl;
                            if(answerToEdit == alphabet){
                                cout << "What would you like to change it too? ";
                                getline(cin, options[i]);
                                cout << "Changes saved! Which options would you like to edit? Press 'q' when ready to quit editing" << endl;
                            }
                        ++alphabet;
                    }
                    }
                }
                else if(menuChoice == 'm'){
                    menuChoice = 'q'; // Quit out of the editing process
                    r = 0;
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

    return r;
}