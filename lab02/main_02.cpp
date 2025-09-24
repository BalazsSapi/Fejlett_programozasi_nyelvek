#include <iostream>
#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
	Point p1(2, 3);
	//cout << "p1( " << p1.getX() << "," << p1.getY() << ")" << endl;

	Point p2(100, 200);
	//cout << "p2( " << p2.getX() << "," << p2.getY() << ")" << endl;

	Point* pp1 = new Point(300, 400);
	Point* pp2 = new Point(500, 1000);
	//cout << "pp1( " << pp1->getX() << "," << pp1->getY() << ")" << endl;
	//cout << "pp2( " << pp2->getX() << "," << pp2->getY() << ")" << endl;

	//cout<<distance(Point(1,1), Point(1,2))<<endl;

	//pp1->print();

	//cout<<isSquare(Point(1,1), Point(1,2),Point(2,2),Point(2,5))<<endl;

	//testIsSquare("data/in.txt");

	Point* points = random_points(5);
	for(int i=0; i<5; i++) {
		points[i].print();
	}

	delete[] points;
	delete pp1;
	delete pp2;
	return 0;
}
