//
// Created by domok on 2025. 11. 24.
//

#include "StudentServiceImpl.h"

vector<string> StudentServiceImpl::getSubjects(int id) const {
    vector<string> subjects;
    for (const auto& g : dao->findById(id).getGrades()) {
        subjects.push_back(g.first);
    }
    return subjects;
}
