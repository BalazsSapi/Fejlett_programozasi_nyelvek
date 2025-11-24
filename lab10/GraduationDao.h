//
// Created by domokos.balazs on 19.11.2025.
//

#ifndef LAB10_GRADUATIONDAO_H
#define LAB10_GRADUATIONDAO_H
#include <map>

#include "Student.h"

using namespace std;

class GraduationDao {
private:
    int year{2023};
    map<int, Student> students;
public:
    GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void readGradesSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    Student findById(int id) const; //throws out_of_range exception for nonexistent id
    double getAverageBySubject(const string &subject) const;
};


#endif //LAB10_GRADUATIONDAO_H