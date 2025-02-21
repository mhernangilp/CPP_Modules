#include "iter.hpp"
#include <iostream>

template <typename T>
void printElement(T const &element) {
    std::cout << element << " ";
}

void increment(int &n) {
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array: ";
    ::iter(arr, len, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing Elements..." << std::endl;
    ::iter(arr, len, increment);

    std::cout << "Modified Array: ";
    ::iter(arr, len, printElement<int>);
    std::cout << std::endl;

    std::cout << "Example With Strings:" << std::endl;
    std::string strArr[] = {"Jamon", "Salchichon", "Fuet"};
    ::iter(strArr, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
