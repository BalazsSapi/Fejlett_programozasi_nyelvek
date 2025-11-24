//
// Created by domokos.balazs on 19.11.2025.
//

#include "GraduationDao.h"

#include <fstream>

using namespace std;

void GraduationDao::enrollStudents(const string &filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Error opening file" << endl;
        exit(-1);
    }
    int id;
    string firstName, lastName;
    while (in>>id>>firstName>>lastName) {
        students.insert({id, Student(id, firstName, lastName)});
    }
    in.close();
}

void GraduationDao::readGradesSubject(const string &subject, const string &filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Error opening file" << endl;
        exit(-1);
    }
    int id;
    double grade;
    while (in>>id>>grade) {
        students[id].addGrade(subject, grade);
    }
    in.close();
}

void GraduationDao::computeAverage() {
    for (auto student : students) {
        student.second.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int passed = 0;
    for (auto student : students) {
        student.second.computeAverage();
        if (student.second.getAverage()>=6) {
            passed++;
        }
    }
    return passed;
}

Student GraduationDao::findById(int id) const {
    if (students.contains(id)==false) {
        throw out_of_range("nonexistent id");
    }
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double sum = 0;
    for (const auto& student : students) {
        sum+=student.second.getGrade(subject);
    }
    return sum/students.size();
}
