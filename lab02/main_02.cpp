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

	Point* points = random_points(1000000);
	//printArray(points, 15);
	//cout << endl;
	//closestPoints(points,100).first.print();
	//closestPoints(points,100).second.print();
	//farthestPoints(points, 100).first.print();
	//farthestPoints(points, 100).second.print();

	//sortPointsByAbscissa(points, 5);
	//printArray(points, 5);

	//Point* returns=farthestPointsFromOrigin(points, 15);
	//printArray(returns, 10);

	//deletePoints(returns);

	cout << endl;
	cout << endl;

	pair<Point,Point> res=closestPointsEfficient(points,1000000);
	res.first.print();
	res.second.print();

	// pair<Point,Point> res=farthestPointsEfficient(points,1000000);
	// res.first.print();
	// res.second.print();

	deletePoints(points);

	delete pp1;
	delete pp2;
	return 0;
}
