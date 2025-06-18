#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        std::cout << "Value not found" << std::endl;
        return it;
    }
    std::cout << "Value found: " << *it << std::endl;
    return it;
}

#endif