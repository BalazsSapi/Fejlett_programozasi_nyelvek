#include <iostream>

#include "Directory.h"
#include "File.h"

using namespace std;

int main() {
    Directory *d1 = new Directory("root");
    d1->add(new Directory("documents"));
    ((Directory *)d1->find("documents"))->add(new File("reports.txt",1500));
    ((Directory *)d1->find("documents"))->add(new File("notes.txt",800));
    d1->add(new Directory("pictures"));
    ((Directory *)d1->find("pictures"))->add(new File("photo1.jpg",2048000));
    ((Directory *)d1->find("pictures"))->add(new File("photo2.jpg",1856000));
    d1->add(new File("readme.txt",500));
    d1->display();
    cout<<d1->getSize()<<endl;

    Directory *d2 = new Directory(*((Directory *)(d1->find("pictures"))));
    d2->display();
    d2->remove("photo1.jpg");
    (*d2)-="photo2.jpg";
    (*d2) += new File ("photo1.jpg",2048000);
    //(*d2) += new Directory (*d2);
    d2->display();

    (*d1)-="pictures";
    d1->display();



    delete d1;
    delete d2;
    return 0;
}