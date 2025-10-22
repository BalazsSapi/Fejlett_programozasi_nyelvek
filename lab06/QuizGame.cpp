//
// Created by domokos.balazs on 22.10.2025.
//

#include "QuizGame.h"

void QuizGame::runGame() {
    int correct=0;
    cout<<quiz.getName()<<endl;
    for (int i=0; i<quiz.getItems().size(); i++) {
        cout<<quiz.getItems()[i].getQuestion()<<endl;
        for (int j=0; j<quiz.getItems()[i].getAnswers().size(); j++) {
            cout<<j+1<<": "<<quiz.getItems()[i].getAnswers()[j]<<endl;
        }
        int answer;
        cin>>answer;
        if (answer-1>=0 && answer-1<quiz.getItems()[i].getAnswers().size()) {
            if (answer-1==quiz.getItems()[i].getCorrectAnswerIndex()) {
                cout<<"Helyes!"<<endl<<endl;
                correct++;
            }
            else {
                cout<<"Rossz valasz!"<<endl<<endl;
            }
        }
        else {
            cout<<"Nincs ilyen válaszlehetoseg!"<<endl<<endl;
            i--;
        }
    }
    cout<<"Vege a quiznek, az elert eredmeny: "<<correct<<"/"<<quiz.getItems().size()<<"->"<<(double)correct/quiz.getItems().size()<<endl<<endl;
    user.add_result(quiz.getId(),correct/quiz.getItems().size());
}
