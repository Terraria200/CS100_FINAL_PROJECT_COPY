#include "../header/QuizConstructor.h"
#include <sstream>

/* Didn't do jackshit
#include <iostream>
#include <string>
*/

QuizConstructor::QuizConstructor(){
}

QuizConstructor::QuizConstructor(Quiz *quiz){
    this->quiz = quiz;
}

Quiz * QuizConstructor::JsonToQuiz(string filename){
    // Return quiz object
    return quiz;
}

void QuizConstructor::setAnswer(){
    string correctAnswer;
    getline(cin, correctAnswer, '\n');
}

void QuizConstructor::editQuestion(ostream& os, istream& is, char menuChoice, int questionToEdit, char answerToEdit, Quiz& quiz){ 
    //char menuChoice = 'g'; // Parameter 1
    //int questionToEdit; // Parameter 2
    //char answerToEdit; // Parameter 3
    for(int i = 0; i < quiz.questions.size(); ++i){
        if(questionToEdit == i){

            os >> "Enter new question: " << endl;
            getline(is, quiz.questions[i]->content);
            os >> "Enter new answer: " << endl;
            getline(is, quiz.questions[i]->answer);
            return;
            /* cout << "Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
            cin >> menuChoice; 
            cout << endl; */
            /* if(menuChoice == 'q'){
                cout << "Old question is \"";
                quiz.displayQuestion(questionToEdit, cout);
                cout << "\" Enter the new or edited question: ";

                // TEMPORARY FIX: only TrueOrFalse questions are supported at the moment
                string newQuestion;
                getline(cin, newQuestion);
                quiz.editQuestion(questionToEdit, new TrueOrFalse(newQuestion, 1, true));

                cout << endl;
                cout << "Changes saved! Select 'q' to edit the question, 'a' to edit the answers, 'm' to quit: ";
            }
            else if(menuChoice == 'a'){
                cout << "Which options would you like to edit? Press 'q' when ready to quit editing" << endl;

                char alphabet = 'a'; */
                
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
            /* else if(menuChoice == 'm'){
                menuChoice = 'q'; // Quit out of the editing process
            }
            else {
                menuChoice == 'b'; // Not a valid question number, so try edit process again
            }
        }
        else{
            menuChoice= 'b'; // Not a valid question number, so try edit process again
        }
    } */
    }
}

void QuizConstructor::editQuiz(ostream &os, istream &is, char menuChoice, int questionToEdit, char answerToEdit, QuizConstructor quizConstructor){ // do the minute details (addQuestion, removeQuestion) for editQuestion. Creating the quiz essentially
    /* Question question1("What is 1 + 1?", 1);
    Question question2("What is 69 + 420?", 1);  */

    stringstream os;
    stringstream is;
   
    /* quiz.addQuestion(question1);
    quiz.addQuestion(question2); */

    os << "Enter menu choice: a to add question, r to remove question, e to edit question";
    //getline(is, menuChoice);

    os << "Enter question # to edit or remove: ";
    //is >> questionToEdit;

    os << "Enter answer to edit, remove, or add: ";
    //getline(is, answerToEdit);
    
    quizConstructor.editQuestion(os, is, menuChoice, questionToEdit, answerToEdit, quizConstructor.quiz);
}

Question* QuizConstructor::createTrueFalseQuestion(ostream &os, istream &is){
    string question;
    string answer;
    int score;

    os << "Enter the question: ";
    getline(is, question);
    os << "Enter the answer: ";
    getline(is, answer);

    // Turn answer into a boolean
    if(answer == "true"){
        answer = "1";
    }
    else if(answer == "false"){
        answer = "0";
    }
    else{
        os << "Invalid answer. Please enter either 'true' or 'false'." << endl;
        return nullptr;
    }

    return new TrueOrFalse(question, score, stoi(answer));
}