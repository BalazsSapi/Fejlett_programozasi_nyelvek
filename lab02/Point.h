#ifndef POINT_H
#define POINT_H
#include <utility>
#include <vector>

using namespace std;

class Point{
        private:
            int x, y;
        public:
            Point( int x=0, int y=0);
            int getX() const;
            int getY() const;
            void print() const;
            /*bool operator<(const Point& other) const {
                if (x == other.x) return y < other.y;
                return x < other.x;
            }*/
    };

    double distance(const Point& a, const Point& b);
    bool isSquare(const Point& a, const Point& b, const Point& c, const Point&d);
    void testIsSquare(const char * filename);
    Point* random_points(const int n);
    void printArray(Point* points, int numPoints);
    pair<Point, Point> closestPoints(Point* points, int numPoints);
    pair<Point, Point> farthestPoints(Point* points, int numPoints);
    void sortPointsByAbscissa(Point* points, int numPoints);
    Point* farthestPointsFromOrigin(Point* points, int numPoints);
    void deletePoints(Point* points);
    pair<Point, Point> closestPointsEfficient(Point* points, int numPoints);
    pair<Point, Point> closestUtil(Point* pts, int l, int r, double& best);
    vector<Point> convexHull(vector<Point>& pts);
    pair<Point, Point> farthestPointsEfficient(Point* points, int numPoints);
#endif /* PONT_H */