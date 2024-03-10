#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point& original): _x(original.getX()), _y(original.getY()) {}

Point& Point::operator=(const Point& original)
{
    if (this != &original) {
        (Fixed)this->_x = original.getX();
        (Fixed)this->_y = original.getY();
    }
    return *this;
}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
    return _x;
}

Fixed Point::getY(void) const
{
    return _y;
}
