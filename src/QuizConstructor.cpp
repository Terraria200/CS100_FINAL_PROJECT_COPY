#include "../header/json.hpp"
#include <iostream>
#include <fstream>
#include "QuizConstructor.h"

QuizConstructor::QuizConstructor(){
}

Quiz * QuizConstructor::JSONToQuiz(string filename){
    // Create a new quiz object
    Quiz *quiz = new Quiz();

    // Open the file
    ifstream file(filename);

    // Check if the file is open
    if(file.is_open()){
        // Create a json object
        nlohmann::json j;
        file >> j;

        // Get the questions from the json object
        nlohmann::json questions = j["questions"];

        // Loop through the questions
        for(nlohmann::json::iterator it = questions.begin(); it != questions.end(); ++it){
            // Get the question type
            string type = it.value()["type"];

            // Create a new question object
            Question *q;

            // Check the question type
            if(type == "true-or-false"){
                // Create a new true or false question
                q = new TrueOrFalse(it.value()["question"], it.value()["points"], it.value()["answer"]);
            } 
                else if(type == "multiple-choice"){
                    // Create a new multiple choice question
                    q = new MultiChoice(it.value()["question"], it.value()["points"], it.value()["options"], it.value()["answer"]);
                }
            // else if(type == "fill-in-the-blank"){
            //     // Create a new short answer question
            //     q = new FillInTheBlank(it.value()["question"], it.value()["points"], it.value()["answer"]);
            // }

            // Add the question to the quiz
            quiz->addQuestion(q);
        }

        // Close the file
        file.close();
    }
    else{
        // Output current working directory
        system("pwd");
        throw runtime_error("File not found");
        return nullptr;
    }

    return quiz;
}

void QuizConstructor::quizToJSON(Quiz* quiz, string filename) {
    // Create a json object
    nlohmann::json j;

    // Create a json array
    nlohmann::json questions;

    // Loop through the questions
    for(Question* q : quiz->getQuestions()){
        // Create a json object
        nlohmann::json question;

        // Set the question type
        question["type"] = q->getType();

        // Set the question
        question["question"] = q->getQuestion();

        // Set the points
        question["points"] = q->getScore();

        // Check the question type
        if(q->getType() == "true-or-false"){
            // Set the answer
            bool answer = dynamic_cast<TrueOrFalse*>(q)->getBoolAnswer();
            
            question["answer"] = answer;
        } 
        else if(q->getType() == "multiple-choice"){
            // Set the options
            question["options"] = dynamic_cast<MultiChoice*>(q)->getOptions();

        //     // Set the answer
        //     question["answer"] = dynamic_cast<MultiChoice*>(q)->getAnswer();
        // } 
        // else if(q->getType() == "fill-in-the-blank"){
        //     // Set the answer
        //     question["answer"] = dynamic_cast<FillInTheBlank*>(q)->getAnswer();
        // }

        // Add the question to the json array
        questions.push_back(question);
    }

    // Add the questions to the json object
    j["questions"] = questions;

    // Open the file
    ofstream file(filename);

    // Write the json object to the file
    file << j;

    // Close the file
    file.close();

}

Quiz * QuizConstructor::createQuiz(ostream &os, istream &is, string title){
    // Create new quiz object
    Quiz *quiz = new Quiz(title);

    // Prompt the user for number of questions
    os << "Enter the number of questions: ";
    int numQuestions;
    is >> numQuestions;
    is.ignore();

    // Loop and add new questions to quiz
    for(int i = 0; i < numQuestions; i++){
        // Prompt the user for question type
        os << "Enter the question type (true-or-false, multiple-choice, fill-in-the-blank): ";
        string type;
        is >> type;
        is.ignore();

        // Create a new question
        Question *q;

        // Check the question type
        if(type == "true-or-false"){
            // Create a new true or false question
            q = createTrueFalseQuestion(os, is);
        } 
        else if(type == "multiple-choice"){
            // Create a new multiple choice question
            q = createMultipleChoiceQuestion(os, is);
        }
        // else if(type == "fill-in-the-blank"){
        //     // Create a new fill in the blank question
        //     q = createFillInTheBlankQuestion(os, is);
        // }
        else{
            throw runtime_error("Invalid question type");
        }

        // Add the question to quiz
        quiz->addQuestion(q);
    }

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

Question* QuizConstructor::createTrueFalseQuestion(ostream &os, istream &is){
    string question;
    string answer;
    int score;

    os << "Enter the question: ";
    getline(is, question, '\n');
    os << "Enter the answer: ";
    getline(is, answer, '\n');

    // Turn answer into a boolean
    if(answer == "true"){
        answer = "1";
    }
    else if(answer == "false"){
        answer = "0";
    }
    else{
        throw runtime_error("Invalid answer");
    }

    os << "Enter the score: ";
    is >> score;

    return new TrueOrFalse(question, score, stoi(answer));
}

Question* QuizConstructor::createMultiChoiceQuestion(ostream &os, istream &is) {
    std::string question;
    int answer;
    int score;
    int numOptions;
    std::string optionAnswer;
    std::vector<std::string> multiChoiceOptions;

    os << "Enter the question: ";
    getline(is, question, '\n');
    os << "Enter number of options up to 4: ";
    cin >> numOptions;

    if (numOptions > 4) {
        os << "Invalid number of options. Enter number of options less than or equal to 4: ";
        cin >> numOptions;
    }

    for (unsigned int i = 1, i < numOptions + 1, i++) {
        os << "Enter answer for option " << i ": ";
        getline(is, optionAnswer, '\n');
        os << endl;
        multiChoiceOptions.push_back(optionAnswer);
    }

    os << "Enter integer answer: ";
    is >> answer;

    os << "Enter the score: ";
    is >> score;

    return new MultiChoice(question, score, answer, mutliChoiceOptions);
}