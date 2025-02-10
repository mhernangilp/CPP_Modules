#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data {
    std::string name;
    int age;
    std::string city;
};

class Serializer {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(const Serializer& original);
        Serializer& operator=(const Serializer& original);
        ~Serializer();
};

#endif