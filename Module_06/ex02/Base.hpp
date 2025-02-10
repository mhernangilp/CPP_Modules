#ifndef Base_HPP
#define Base_HPP

#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

class A;
class B;
class C;

class Base {
    public:
        virtual ~Base();

        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};

#endif