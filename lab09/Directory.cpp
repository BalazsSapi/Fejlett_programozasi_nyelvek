//
// Created by domokos.balazs on 12.11.2025.
//

#include "Directory.h"
#include <algorithm>

Directory::Directory(const Directory &directory) {
    name=directory.name;
    for (int i=0;i<directory.children.size();i++) {
        children.push_back(directory.children[i]->clone());
    }
}

FileSystemItem * Directory::clone() const {
    return new Directory(*this);

}

void Directory::add(FileSystemItem *item) {
    children.push_back(item);
}

void Directory::remove(const string &name) {
    FileSystemItem *p=find(name);
    if (p==nullptr) {
        cout<<"File can not be removed!";
        return;
    }
    children.erase(std::find(children.begin(),children.end(),p));
    delete p;

}

FileSystemItem * Directory::find(const string &name) {
    for (int i=0; i<children.size();i++) {
        if (children[i]->getName()==name) {
            return children[i];
        }
    }
    return nullptr;
}

void Directory::display(ostream &out, int depth) const {
    for (int i=0; i<depth; i++) {
        out<<'\t';
    }
    out<<name<<endl;
    for (int i=0; i<children.size(); i++) {
        children[i]->display(out,depth+1);
    }
}

int Directory::getSize() const {
    int sum=0;
    for (auto &c : children) {
        sum+=c->getSize();
    }
    return sum;
}

void operator+=(Directory &directory, FileSystemItem *item) {
    directory.add(item);
}

void operator-=(Directory &directory, const string &item) {
    directory.remove(item);
}
