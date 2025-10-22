//
// Created by domokos.balazs on 22.10.2025.
//

#ifndef LAB6_QUIZITEM_H
#define LAB6_QUIZITEM_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;


class QuizItem {

private:
    static int counter;
    int id;
    string question;
    vector<string> answers;
    int correctAnswerIndex;

public:
    QuizItem(const string &question, const vector<string> &answers, int correct_answer_index)
        : question(question),
          answers(answers),
          correctAnswerIndex(correct_answer_index) {
          id=++counter;
    }
    int getId () { return id; }
    string getQuestion () { return question; }
    vector<string> getAnswers () { return answers; }
    int getCorrectAnswerIndex () { return correctAnswerIndex; }
};


#endif //LAB6_QUIZITEM_H