#include "Serializer.hpp"

int main() {
    Data data;
    data.name = "Kerry Caverga";
    data.age = 42;
    data.city = "Albacete";

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << std::endl;
    std::cout << "City: " << deserialized->city << std::endl;

    return 0;
}