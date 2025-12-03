#include <iostream>

#include "SimpleTextGenerator.h"

using namespace std;

int main() {
    SimpleTextGenerator simpleText;
    simpleText.trainFromFile("data/in.txt");
    cout<<simpleText.generate("For sleep", 6);
    return 0;
}
