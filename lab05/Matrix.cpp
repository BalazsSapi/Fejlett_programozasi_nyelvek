//
// Created by domokos.balazs on 15.10.2025.
//

#include "Matrix.h"

#include <climits>
#include <iomanip>

using namespace std;

Matrix::Matrix(int rows, int cols): mRows(rows), mCols(cols), mElements(mRows*mCols, 0) {
}

Matrix::Matrix(const Matrix &other): mRows(other.mRows), mCols(other.mCols), mElements(other.mElements){
}

Matrix::Matrix(Matrix &&other) noexcept: mRows(other.mRows), mCols(other.mCols), mElements(move(other.mElements)){
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(0));
    for (int i=0; i<mRows*mCols; ++i) {
        mElements[i]=a+((double)rand()/RAND_MAX)*(b-a);
    }
}

void Matrix::printMatrix(std::ostream &os) const {
    for (int i=0; i<mRows; i++) {
        for (int j=0; j<mCols; j++) {
            os<<setw(8)<<mElements[i*mCols+j]<<" ";
        }
        os<<endl;
    }
    os<<endl;
}

double * Matrix::operator[](int row) {
    return &mElements[row*mCols];
}

const double * Matrix::operator[](int row) const {
    return &mElements[row*mCols];
}

double & Matrix::operator()(int row, int col) {
    if (row>=mRows) {
        throw out_of_range("Index out of bounds");
    }
    if (col>=mCols) {
        throw out_of_range("Index out of bounds");
    }
    return mElements[row*mCols+col];
}

const double & Matrix::operator()(int row, int col) const {
    return mElements[row*mCols+col];
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mCols) {
        throw out_of_range("The two matrices don't have the same size");
    }
    if (x.mRows != y.mRows) {
        throw out_of_range("The two matrices don't have the same size");
    }
    Matrix m(x.mRows,x.mCols);
    for (int i=0; i<x.mRows; i++) {
        for (int j=0; j<x.mCols; j++) {
            m[i][j]=x[i][j]+y[i][j];
        }
    }
    return m;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols!=y.mRows) {
        throw out_of_range("The two matrices are not compatible with the * operator");
    }
    Matrix m(x.mRows,y.mCols);
    for (int i=0; i<x.mRows; i++) {
        for (int j=0; j<y.mCols; j++) {

        }
    }
}

istream & operator>>(std::istream &is, Matrix &mat) {
    for (int i=0; i<mat.mRows; i++) {
        for (int j=0; j<mat.mCols; j++) {
            is>>mat.mElements[i*mat.mCols+mat.mRows];
        }
    }
    return is;
}

ostream & operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}
