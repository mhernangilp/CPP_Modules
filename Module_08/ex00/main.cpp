#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main() {
    // Prueba con std::vector
    std::vector<int> vec;
    for (int i = 1; i <= 5; ++i)
        vec.push_back(i * 10); // 10, 20, 30, 40, 50

    std::cout << "Testing vector:\n";
    easyfind(vec, 30); // Should find
    easyfind(vec, 99); // Should not find

    // Prueba con std::list
    std::list<int> lst;
    lst.push_back(3);
    lst.push_back(6);
    lst.push_back(9);

    std::cout << "\nTesting list:\n";
    easyfind(lst, 6);  // Should find
    easyfind(lst, 4);  // Should not find

    // Prueba con std::deque
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    std::cout << "\nTesting deque:\n";
    easyfind(deq, 200); // Should find
    easyfind(deq, 500); // Should not find

    return 0;
}
