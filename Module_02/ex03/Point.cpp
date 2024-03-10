#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(Point& original): _x(original.getX()), _y(original.getY()) {}

Point& Point::operator=(Point& original)
{
    if (this != &original) {
        _x = original.getX();
        _y = original.getY();
    }
    return *this;
}

Point::~Point(void) {}

Fixed Point::getX(void)
{
    return _x;
}

Fixed Point::getY(void)
{
    return _y;
}
