#include "bsp.hpp"

static Fixed abs(Fixed area)
{
    if (area < 0)
        return (area * -1);
    return area;
}

static Fixed area(Point const& a, Point const& b, Point const& c)
{
    return abs((a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(a.getY() - b.getY())) / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed   totalArea = area(a, b, c);
    Fixed   area1 = area(point, b, c);
    Fixed   area2 = area(a, point, c);
    Fixed   area3 = area(a, b, point);

    return (totalArea == area1 + area2 + area3);
}