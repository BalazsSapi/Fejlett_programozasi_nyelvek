//
// Created by domokos.balazs on 19.11.2025.
//

#ifndef LAB10_STUDENT_H
#define LAB10_STUDENT_H
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(const int id=0, const string &firstName="", const string &lastName="") : id(id), firstName(firstName), lastName(lastName) {}
    int getId() const {return id;}
    const string &getFirstName()const {return firstName;}
    const string &getLastName() const {return lastName;}
    void addGrade(const string& subject, double grade) {
        grades[subject]=grade;
    }

    //throws out_of_range for nonexistent subject
    double getGrade(const string& subject) const {
        if (grades.contains(subject)==false) {
            throw out_of_range("nonexistent subject");
        }
        return grades.at(subject);
    }
    const map<string, double> &getGrades() const {
        return grades;
    }
    void computeAverage();
    double getAverage() {
        if (average==0) {
            computeAverage();
        }
        return average;

    }
    friend ostream& operator<<(ostream& out, const Student& student);
};


#endif //LAB10_STUDENT_H