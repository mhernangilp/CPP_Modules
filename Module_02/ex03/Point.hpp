#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        Fixed _x;
        Fixed _y;

    public:
        Point(void);
        Point(const float x, const float y);
        Point(Point& original);
        Point& operator=(Point& original);
        ~Point(void);

        Fixed getX(void);
        Fixed getY(void);
};

#endif