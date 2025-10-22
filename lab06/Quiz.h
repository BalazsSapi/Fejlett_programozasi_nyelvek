//
// Created by domokos.balazs on 22.10.2025.
//

#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

#include <iostream>
#include <string>
#include <vector>

#include "QuizItem.h"

using namespace std;

class Quiz {

private:
    static int counter;
    int id;
    string name;
    vector<QuizItem> items;
    bool isReady;

public:
    Quiz(const string &name)
        : name(name) {
        id=counter++;
        isReady=false;
    }
    void addItem(QuizItem item){ items.push_back(item); }
    void setIsReady(){ isReady=true; }
};


#endif //LAB5_QUIZ_H