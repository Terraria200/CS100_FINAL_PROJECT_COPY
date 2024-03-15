#include "../header/json.hpp"
#include <iostream>
#include <fstream>
#include "QuizConstructor.h"

QuizConstructor::QuizConstructor(){
}

Quiz * QuizConstructor::JSONToQuiz(string filename){
    // Open the file
    ifstream file(filename);

    // Check if the file is open
    if(file.is_open()){
        // Create a json object
        nlohmann::json j;
        file >> j;

        // Create a new quiz object
        Quiz *quiz = new Quiz(j["title"]);

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
            // else if(type == "multiple-choice"){
            //     // Create a new multiple choice question
            //     q = new MultiChoice(it.value()["question"], it.value()["points"], it.value()["options"], it.value()["answer"]);
            // } 
            else if(type == "fill-in-the-blank"){
                // Create a new short answer question
                q = new FillInTheBlank(it.value()["question"], it.value()["points"], it.value()["answer"]);
            }

            // Add the question to the quiz
            quiz->addQuestion(q);
        }

        // Close the file
        file.close();
        return quiz;
    }
    else{
        // Output current working directory
        system("pwd");
        throw runtime_error("File not found");
        return nullptr;
    }

}

void QuizConstructor::quizToJSON(Quiz* quiz, string filename) {
    // Create a json object
    nlohmann::json j;

    // Set the quiz title
    j["title"] = quiz->getTitle();

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
        // else if(q->getType() == "multiple-choice"){
        //     // Set the options
        //     question["options"] = dynamic_cast<MultiChoice*>(q)->getOptions();

        //     // Set the answer
        //     question["answer"] = dynamic_cast<MultiChoice*>(q)->getAnswer();
        // } 
        else if(q->getType() == "fill-in-the-blank"){
            // Set the answer
            question["answer"] = q->getAnswer();
        }

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
        // else if(type == "multiple-choice"){
        //     // Create a new multiple choice question
        //     q = createMultipleChoiceQuestion(os, is);
        // } 
        else if(type == "fill-in-the-blank"){
            // Create a new fill in the blank question
            q = createFillInTheBlankQuestion(os, is);
        }
        else{
            throw runtime_error("Invalid question type");
        }

        // Add the question to quiz
        quiz->addQuestion(q);
    }

    return quiz;
}

void QuizConstructor::editQuiz(ostream& os, istream& is, Quiz *quiz){ 
    // Prompt user to see if they want to change title, then change it if they do
    os << "Would you like to change the title? (y/n): ";
    string changeTitle;
    is >> changeTitle;
    is.ignore();
    if(changeTitle == "y"){
        os << "Enter the new title: ";
        string newTitle;
        getline(is, newTitle, '\n');
        quiz->setTitle(newTitle);
        os << "Title changed to " << newTitle << endl;
    }
    
    // Loop for editing questions menu
    bool editing = true;
    while(editing){
        // Display the questions
        quiz->displayQuestions(os);

        // Prompt user for adding, removing, or editing a question
        os << "Would you like to add, remove, or edit a question? (add/remove/edit/exit): ";
        string choice;
        is >> choice;
        is.ignore();

        // Add a question
        if(choice == "add"){
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
            // else if(type == "multiple-choice"){
            //     // Create a new multiple choice question
            //     q = createMultipleChoiceQuestion(os, is);
            // } 
            else if(type == "fill-in-the-blank"){
                // Create a new fill in the blank question
                q = createFillInTheBlankQuestion(os, is);
            }
            else{
                throw runtime_error("Invalid question type");
            }

            // Add the question to quiz
            quiz->addQuestion(q);
        }

        // Remove a question
        else if(choice == "remove"){
            // Prompt the user for the question number
            os << "Enter the number of the question you would like to remove: ";
            int questionNumber;;
            is >> questionNumber;
            is.ignore();

            int index = questionNumber - 1;

            // Remove the question
            quiz->removeQuestion(index);
        }

        // Edit a question
        else if(choice == "edit"){
            // Prompt the user for the question number
            os << "Enter the number of the question you would like to edit: ";
            int questionNumber;
            is >> questionNumber;
            is.ignore();

            int index = questionNumber - 1;

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
            // else if(type == "multiple-choice"){
            //     // Create a new multiple choice question
            //     q = createMultipleChoiceQuestion(os, is);
            // } 
            else if(type == "fill-in-the-blank"){
                // Create a new fill in the blank question
                q = createFillInTheBlankQuestion(os, is);
            }
            else{
                throw runtime_error("Invalid question type");
            }

            // Edit the question
            quiz->editQuestion(index, q);
        }

        // Exit
        else {
            editing = false;
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

    //Convert to lowercase
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

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

Question* QuizConstructor::createFillInTheBlankQuestion(ostream &os, istream &is) {
    string question;
    string answer;
    int score;

    os << "Enter the question: ";
    getline(is, question, '\n');
    os << "Enter the answer: ";
    getline(is, answer, '\n');
    os << "Enter the score: ";
    is >> score;

    return new FillInTheBlank(question, score, answer);    
}