#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(T const &element) {
    std::cout << element << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array: " << std::endl;
    ::iter(arr, len, printElement<int>);
    std::cout << std::endl;

    std::cout << "Example With Strings:" << std::endl;
    std::string strArr[] = {"Jamon", "Salchichon", "Fuet"};
    ::iter(strArr, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
