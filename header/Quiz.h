#include <vector>
#include <iostream>
#include "../header/Question.h"

class Quiz {
private:
    std::vector<Question*> questions;
    unsigned score;
public:
    Quiz();
    void addQuestion(Question* question);
    void start(std::ostream& os, std::istream& is);
    unsigned getScore();
    void reset();
    void clear();
    ~Quiz();
};