#include "bsp.hpp"
#include <iostream>

/*            B(10,30)
                / \
               /   \
              /     \
             /   d   \      e
            /         \
     A(0,0) ----------- C(20,0) */

int main( void ) {
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point d(10, 15);
    Point e(30, 15);

    if (bsp(a, b, c, d))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Not inside triangle" << std::endl;
    if (bsp(a, b, c, e))
        std::cout << "Inside triangle" << std::endl;
    else
        std::cout << "Not inside triangle" << std::endl;
    return (0);
}