//
// Created by domokos.balazs on 01.10.2025.
//

#include "Point.h"

#include <cmath>

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

double Point::distanceTo(const Point &point) const {
    return sqrt((x-point.getX())*(x-point.getX()) + (y-point.getY())*(y-point.getY()));
}
