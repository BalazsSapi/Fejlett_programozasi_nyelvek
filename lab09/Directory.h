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
    Directory(const Directory &directory);
    ~Directory() {
        for (auto c : children) {
            delete c;
        }
    }
    FileSystemItem *clone() const override;
    void add(FileSystemItem* item);
    void remove(const string& name);
    FileSystemItem* find(const string& name);
    void display(ostream &out=cout, int depth=0) const override;
    int getSize() const;
    friend void operator+=(Directory &directory, FileSystemItem *item);
    friend void operator-=(Directory &directory, const string &item);
};


#endif //LAB9_DIRECTORY_H