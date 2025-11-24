//
// Created by domok on 2025. 11. 24..
//

#ifndef LAB10_STUDENTSERVICEIMPL_H
#define LAB10_STUDENTSERVICEIMPL_H
#include "StudentService.h"


using namespace std;

class StudentServiceImpl : public StudentService {
    GraduationDao *dao;

public:
    StudentServiceImpl(GraduationDao *dao) : dao(dao) {
    }

    bool isEnrolled(int id) const override {
        try {
            dao->findById(id);
            return true;
        }
        catch (exception &e) {
            return false;
        }
    }

    vector<string> getSubjects(int id) const override;

    double getResultBySubject(int id, const string &subject) const override {
        return dao->findById(id).getGrade(subject);
    }

    double getAverage(int id) const override {
        return dao->findById(id).getAverage();
    }

    bool isPassed(int id) const override {
        return dao->findById(id).getAverage()>=6;
    }
};

#endif //LAB10_STUDENTSERVICEIMPL_H