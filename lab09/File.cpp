//
// Created by domokos.balazs on 12.11.2025.
//

#include "File.h"


File::File(const string &name, const long size) : FileSystemItem(name), size(size) {
}

// void display(ostream &out, int depth = 0) const override;
void File::display(ostream &out, int depth) const {
    for (int i=0;i<depth;i++) {
        out<<'\t';
    }
    out<<name<<" ("<<size<<" bytes)"<<endl;
}

FileSystemItem * File::clone() const {
    return new File(*this);
}

