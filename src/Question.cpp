#include "../header/Question.h"

boolean MultiChoice::checkAnswer(){
    if(inputAnswer == correctAnswer){
        return true;
    }
    else{
        return false;
    }
}

void MultiChoice::changeScore(){
    if(checkAnswer() == true){
        ++score;
    }
    else{
        --score;
    }
}