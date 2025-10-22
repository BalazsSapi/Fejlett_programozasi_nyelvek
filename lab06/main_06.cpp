#include <iostream>
#include <fstream>
#include "Quiz.h"
#include "QuizGame.h"
#include "User.h"

using namespace std;


int main() {
    User me("Balazs");
    Quiz q1("Elso quiz!");
    q1.readQuizFromFile("data/in.txt");
    QuizGame qg(me,q1);
    qg.runGame();
    return 0;
}