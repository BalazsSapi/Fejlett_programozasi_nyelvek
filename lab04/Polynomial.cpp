//
// Created by domokos.balazs on 08.10.2025.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double coefficients[]) {
    capacity=degree+1;
    this->coefficients=new double[capacity];
    for (int i=0; i<capacity; i++) {
        this->coefficients[i]=coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    capacity=that.capacity;
    coefficients=new double[capacity];
    for (int i=0; i<capacity; i++) {
        coefficients[i]=that.coefficients[i];
    }
}

Polynomial::~Polynomial() {
    if (coefficients!=nullptr) {
        delete[] coefficients;
    }
}

int Polynomial::degree() const {
    return capacity-1;
}

double Polynomial::evaluate(double x) const {
    double v=coefficients[0];
    for (int i=1;i<capacity; i++) {
        v=v*x+coefficients[i];
    }
    return v;
}

Polynomial Polynomial::derivative() const {
    double arr[capacity-1];
    for (int i=0; i<capacity-1; i++) {
        arr[i]=coefficients[i]*(capacity-1-i);
    }
    return Polynomial(capacity-2,arr);
}

double Polynomial::operator[](int index) const {
    return coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    double arr[a.capacity];
    for (int i=0; i<a.capacity; i++) {
        arr[i]=-a.coefficients[i];
    }
    return Polynomial(a.capacity-1,arr);
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    int a_1=0,b_1=0,capacity;
    double *arr;
    if (a.capacity>b.capacity) {
        a_1=a.capacity-b.capacity;
        capacity=a.capacity;
        arr=a.coefficients;
    }
    else {
        b_1=b.capacity-a.capacity;
        capacity=b.capacity;
        arr=b.coefficients;
    }
    Polynomial p(capacity-1,arr);
    for (int i=0; i<capacity-a_1-b_1;i++) {
        p.coefficients[i+a_1+b_1]=a.coefficients[i+a_1]+b.coefficients[i+b_1];
    }
    return p;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    return -b+a;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    int capacity=a.capacity+b.capacity-1;
    double arr[capacity]={0};
    for (int i=0; i<a.capacity; i++) {
        for (int j=0; j<b.capacity; j++) {
            arr[i+j]+=a.coefficients[i]*b.coefficients[j];
        }
    }
    return Polynomial(capacity-1,arr);
}

ostream & operator<<(ostream &out, const Polynomial &what) {
    for (int i=0;i<what.capacity-1;i++) {
        out<<what.coefficients[i]<<"(x^"<<what.capacity-1-i<<")"<<((what.coefficients[i+1]>=0)? "+" : "");
    }
    out<<what.coefficients[what.capacity-1]<<endl;
    return out;
}