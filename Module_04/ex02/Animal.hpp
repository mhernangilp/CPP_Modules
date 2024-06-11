#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string.h>
#include <iostream>

class Animal {
    protected:
        std::string type;
    
    public:
        Animal();
        Animal (const Animal& original);
        virtual Animal& operator=(const Animal& original);
        virtual ~Animal();

        std::string getType() const;

        virtual void makeSound() const = 0;
};

#endif