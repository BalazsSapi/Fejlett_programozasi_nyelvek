//
// Created by domokos.balazs on 12.11.2025.
//

#ifndef LAB9_FILESYSTEMITEM_H
#define LAB9_FILESYSTEMITEM_H
#include <string>
#include <iostream>
using namespace std;


class FileSystemItem {
protected:
    string name;

public:
    FileSystemItem(const string &name = "") : name(name) {
    }
    virtual ~FileSystemItem() = default;

    virtual int getSize() const = 0;

    virtual string getName() const {
        return name;
    }

    virtual void display(ostream &out = cout, int depth = 0) const = 0;

    virtual FileSystemItem *clone() const = 0;

    friend ostream &operator<<(ostream &out, const FileSystemItem &fileSystem);

    friend bool operator<(const FileSystemItem &fileSystem1, const FileSystemItem &fileSystem2);
};


#endif //LAB9_FILESYSTEMITEM_H
