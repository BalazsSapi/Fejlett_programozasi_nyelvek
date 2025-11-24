//
// Created by domokos.balazs on 19.11.2025.
//

#include "Student.h"

void Student::computeAverage() {
    double sum=0;
    for (auto s : grades) {
        if (s.second<5) {
            average=0;
            return;
        }
        sum+=s.second;
    }
    average=sum/grades.size();
}

ostream & operator<<(ostream &out, const Student &student) {
    out<<student.id<<": "<<student.firstName<<" "<<student.lastName<<student.average<<endl;
    for (const auto& g : student.grades) {
        out<<g.first<<": "<<g.second<<endl;
    }
    return out;
}
