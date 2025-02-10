#include "Base.hpp"

int main() {
    Base* base = new Base();
    Base* random = base->generate();

    base->identify(random);

    base->identify(*random);

    delete base;
    delete random;

    return 0;
}