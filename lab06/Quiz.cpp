//
// Created by domokos.balazs on 22.10.2025.
//

#include "Quiz.h"
#include <fstream>

int Quiz:: counter=0;

void Quiz::readQuizFromFile(string fileName) {
    string type;
    ifstream in(fileName);
    if (!in) {
        cout<<"File not found!";
        exit(-1);
    }

    while (in>>type) {
        char question[100];
        string questionString;
        int answerIndex;
        char answer[100];
        vector<string> answerString;
        in.getline(question,100);
        questionString=question;
        while (in>>type) {
            if (type!="A") {
                answerIndex=stoi(type)-1;
                break;
            }
            else {
                in.getline(answer,100);
                answerString.push_back(answer);
            }
        }
        items.push_back(QuizItem(questionString,answerString,answerIndex));
    }
    isReady=true;
}
