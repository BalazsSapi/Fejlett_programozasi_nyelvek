//
// Created by domokos.balazs on 22.10.2025.
//

#ifndef LAB5_USER_H
#define LAB5_USER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class User {
private:
    static int counter;
    int id;
    string name;
    map<int,vector<double>> results;

public:
    User(const string &name)
        : name(name) {
        id=counter++;
    }
    void add_result(int quizId, double result) {
        //itt kell folytatni
    }
};


#endif //LAB5_USER_H