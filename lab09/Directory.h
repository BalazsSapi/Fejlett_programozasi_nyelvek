//
// Created by domokos.balazs on 12.11.2025.
//

#ifndef LAB9_DIRECTORY_H
#define LAB9_DIRECTORY_H
#include <vector>
#include "FileSystemItem.h"

using namespace std;

class Directory : public FileSystemItem{
private:
    vector<FileSystemItem*> children;
public:
    Directory(const string& name) : FileSystemItem(name){}
    ~Directory() {
        for (auto c : children) {
            delete c;
        }
    }
};


#endif //LAB9_DIRECTORY_H