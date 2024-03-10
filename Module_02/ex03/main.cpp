#include "Point.hpp"
#include <iostream>

int main( void ) {
    Point a;
    Point b(1.5f, 5.2f);
    Point c(b);
    Point d;
    d = b;

    std::cout << a.getX() << ", " << a.getY() << std::endl;
    std::cout << b.getX() << ", " << b.getY() << std::endl;
    std::cout << c.getX() << ", " << c.getY() << std::endl;
    std::cout << d.getX() << ", " << d.getY() << std::endl;

    return (0);
}