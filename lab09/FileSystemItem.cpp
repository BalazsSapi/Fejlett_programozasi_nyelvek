//
// Created by domokos.balazs on 12.11.2025.
//

#include "FileSystemItem.h"

ostream & operator<<(ostream &out, const FileSystemItem &fileSystem) {
    fileSystem.display(out,0);
    return out;
}

bool operator<(const FileSystemItem &fileSystem1, const FileSystemItem &fileSystem2) {
    return fileSystem1.name<fileSystem2.name;
}
