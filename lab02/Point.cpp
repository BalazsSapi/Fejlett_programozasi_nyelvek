#include "Point.h"
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <ctime>

using namespace std;

Point::Point(int x, int y)
{
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::print() const
{
    cout<<"( " << x << "," << y << " )" <<endl;
}

double distance(const Point& a, const Point& b)
{
    return sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getY() - b.getY(), 2));
}

bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d)
{
    set <double> distances[6];

    distances->insert(::distance(a, b));
    distances->insert(::distance(a, c));
    distances->insert(::distance(a, d));
    distances->insert(::distance(b, c));
    distances->insert(::distance(b, d));
    distances->insert(::distance(c, d));

    if(distances->size() == 2){
        return true;
    }
    return false;
}

void testIsSquare(const char * filename)
{
    ifstream in(filename);

    while(!in.eof()){
        Point A, B, C, D;
        int x,y;
        for(int i=0; i<4; i++){
            in>>x>>y;
            switch(i){
                case 0:
                    A = Point(x,y);
                    break;
                case 1:
                    B = Point(x,y);
                    break;
                case 2:
                    C = Point(x,y);
                    break;
                case 3:
                    D = Point(x,y);
                    break;
            }
        }
        cout<<"A "; A.print();
        cout<<"B "; B.print();
        cout<<"C "; C.print();
        cout<<"D "; D.print();
        if(isSquare(A,B,C,D)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        cout<<endl;
    }

    in.close();
}

Point* random_points(const int n)
{
    srand(std::time({}));
    Point *points=new Point[n];
    for(int i=0; i<n; i++){
        points[i]=Point(rand()%2001, rand()%2001);
    }

    return points;
}