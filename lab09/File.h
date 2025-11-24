//
// Created by domokos.balazs on 12.11.2025.
//

#ifndef LAB9_FILE_H
#define LAB9_FILE_H
#include "FileSystemItem.h"


class File : public FileSystemItem{
private:
    int size;
public:
    File(const string& name="", const long size=0);
    int getSize() const {
        return size;
    }
    void display(ostream &out, int depth) const override;
    FileSystemItem *clone() const override;
};


#endif //LAB9_FILE_H