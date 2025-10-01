#include "Point.h"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <ctime>
#include <float.h>
#include <map>
#include <vector>
#include <bits/ranges_algo.h>

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

Point* random_points(const int n) {
    srand(time(nullptr));
    Point *points=new Point[n];
    set<Point> set;

    while (set.size()<n) {
        set.insert(Point(rand()%2001,rand()%2001));
    }

    /*for(int i=0; i<n; i++){
        points[i]=Point(rand()%2001, rand()%2001);
    }*/
    int i=0;
    for (auto& p : set) {
        points[i] = p;
        i++;
    }

    return points;
}

void printArray(Point* points, int numPoints) {
    for(int i=0; i<numPoints; i++) {
        points[i].print();
    }
}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    double minDist = DBL_MAX;
    pair<Point, Point> closest;
    for(int i=0; i<numPoints; i++) {
        for(int j=i+1; j<numPoints; j++) {
            if (distance(points[i], points[j]) < minDist) {
                minDist = distance(points[i], points[j]);
                closest.first = points[i];
                closest.second = points[j];
            }
        }
    }
    return closest;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    double maxDist = DBL_MIN;
    pair<Point, Point> farthest;
    for(int i=0; i<numPoints; i++) {
        for(int j=i+1; j<numPoints; j++) {
            if (distance(points[i], points[j]) > maxDist) {
                maxDist = distance(points[i], points[j]);
                farthest.first = points[i];
                farthest.second = points[j];
            }
        }
    }
    return farthest;
}

bool mycmp(Point a, Point b) {
    return a.getX() < b.getX();
}

void sortPointsByAbscissa(Point *points, int numPoints) {
    sort(points,points+numPoints,mycmp);
}

Point * farthestPointsFromOrigin(Point *points, int numPoints) {
    map<double, Point> distances;
    for(int i=0; i<numPoints; i++) {
        if (distances.size()<10) {
            distances.insert(pair<double,Point>(distance(points[i],0), points[i]));
        }
        else if (distances.begin()->first<distance(points[i],0)) {
            distances.erase(distances.begin());
            distances.insert(pair<double,Point>(distance(points[i],Point (0,0)), points[i]));
        }
    }

    Point *returns = new Point[distances.size()];
    int i=0;
    for (auto&  element : distances) {
        returns[i++] = element.second;
        //cout<<element.first<<endl;
    }


    return returns;
}

void deletePoints(Point *points) {
    delete[] points;
}

pair<Point, Point> closestUtil(Point* pts, int l, int r, double& best) {
    if (r - l <= 3) {
        pair<Point, Point> res = {pts[l], pts[l+1]};
        best = distance(pts[l], pts[l+1]);
        for (int i=l; i<=r; i++) {
            for (int j=i+1; j<=r; j++) {
                double d = distance(pts[i], pts[j]);
                if (d < best) {
                    best = d;
                    res = {pts[i], pts[j]};
                }
            }
        }
        return res;
    }

    int mid = (l + r) / 2;
    int midX = pts[mid].getX();

    pair<Point, Point> leftPair = closestUtil(pts, l, mid, best);
    pair<Point, Point> rightPair = closestUtil(pts, mid+1, r, best);

    pair<Point, Point> bestPair = (distance(leftPair.first,leftPair.second) <
                                   distance(rightPair.first,rightPair.second))
                                  ? leftPair : rightPair;

    vector<Point> strip;
    for (int i=l; i<=r; i++) {
        if (abs(pts[i].getX() - midX) < best) {
            strip.push_back(pts[i]);
        }
    }
    sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
        return a.getY() < b.getY();
    });

    for (int i=0; i<strip.size(); i++) {
        for (int j=i+1; j<strip.size() &&
             (strip[j].getY()-strip[i].getY()) < best; j++) {
            double d = distance(strip[i], strip[j]);
            if (d < best) {
                best = d;
                bestPair = {strip[i], strip[j]};
            }
             }
    }

    return bestPair;
}

pair<Point, Point> closestPointsEfficient(Point* points, int numPoints) {
    sort(points, points+numPoints, mycmp);
    double best = DBL_MAX;
    return closestUtil(points, 0, numPoints-1, best);
}



// Segédfüggvény a konvex burokhoz
long long cross(const Point& O, const Point& A, const Point& B) {
    return 1LL*(A.getX()-O.getX())*(B.getY()-O.getY()) -
           1LL*(A.getY()-O.getY())*(B.getX()-O.getX());
}

// Konvex burok: Andrew monotone chain
vector<Point> convexHull(vector<Point>& pts) {
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b){
        return a.getX()==b.getX() ? a.getY()<b.getY() : a.getX()<b.getX();
    });

    vector<Point> H;
    for (auto& p : pts) {
        while (H.size()>=2 && cross(H[H.size()-2], H.back(), p) <= 0) H.pop_back();
        H.push_back(p);
    }
    int lowerSize = H.size();
    for (int i=pts.size()-2; i>=0; i--) {
        auto p = pts[i];
        while (H.size()>lowerSize && cross(H[H.size()-2], H.back(), p) <= 0) H.pop_back();
        H.push_back(p);
    }
    H.pop_back(); // utolsó duplikált
    return H;
}

// Rotating calipers az átmérő meghatározásához
pair<Point, Point> farthestPointsEfficient(Point* points, int numPoints) {
    vector<Point> pts(points, points+numPoints);
    vector<Point> hull = convexHull(pts);
    int m = hull.size();

    if (m==1) return {hull[0], hull[0]};
    if (m==2) return {hull[0], hull[1]};

    double maxDist = 0;
    pair<Point, Point> best = {hull[0], hull[0]};

    int j = 1;
    for (int i=0; i<m; i++) {
        int ni = (i+1)%m;
        while (abs(cross(hull[i], hull[ni], hull[(j+1)%m])) >
               abs(cross(hull[i], hull[ni], hull[j]))) {
            j = (j+1)%m;
               }
        double d = distance(hull[i], hull[j]);
        if (d > maxDist) {
            maxDist = d;
            best = {hull[i], hull[j]};
        }
    }
    return best;
}