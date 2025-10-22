//
// Created by domokos.balazs on 22.10.2025.
//

#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include "User.h"
#include "Quiz.h"
#include <iostream>




class QuizGame {

private:
    User &user;
    Quiz &quiz;

public:
    QuizGame (User &user, Quiz &quiz) : user(user), quiz(quiz) {}
    void runGame ();
};


#endif //LAB5_QUIZGAME_H