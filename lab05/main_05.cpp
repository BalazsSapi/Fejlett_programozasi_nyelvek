#include <iostream>

#include "Matrix.h"

using namespace std;

int main() {
    Matrix m1(2,3), m2(3,2);
    m1.randomMatrix(10,50);
    m2.randomMatrix(11, 12);
    cout<<m1<<endl<<m2<<endl;

    cout<<m1*m2<<endl;
}
