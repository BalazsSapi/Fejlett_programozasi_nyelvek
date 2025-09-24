#include "functions.h"

#include <cmath>

using namespace std;

int countBits(int number){
    int counter=0;
    while(number){
        if(number & 1){
            counter++;
        }
        number = number >> 1;
    }
    return counter;
}

bool setBit(int &number, int order){
    if(order>31){
        return false;
    }
    number=number | (1<<order);
    return true;
}

double mean(double array[], int numElements){
    if(numElements==0){
        return NAN;
    }
    double sum=0;
    for(int i=0; i<numElements; i++){
        sum+=array[i];
    }
    return sum/numElements;
}

