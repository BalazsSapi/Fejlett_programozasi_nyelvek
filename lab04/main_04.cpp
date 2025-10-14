#include <iostream>

#include "Polynomial.h"

int main() {
    double arr[]={1,2,1}, arr2[]={2,3,4};
    Polynomial p1(2,arr),p2(2,arr2);
    //cout<<p1.evaluate(2);
    //cout<<p1.degree();

    //cout<<(p1+p2);
    //cout<<endl;

    //cout<<p1.derivative()<<endl;
    //cout<<p1.derivative();

    cout << p1 << endl;
    cout << p2 << endl;
    cout<<p1*p2<<endl;
}