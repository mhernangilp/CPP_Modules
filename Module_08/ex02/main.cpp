#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main() {
    {
        std::cout << "===== Test básico de MutantStack =====" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << "Top: " << mstack.top() << std::endl;

        mstack.pop();

        std::cout << "Size after pop: " << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        std::cout << "\nIterando con iterador normal:" << std::endl;
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        for (; it != ite; ++it) {
            std::cout << *it << std::endl;
        }

        std::cout << "\nIterando con reverse_iterator:" << std::endl;
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << std::endl;
        }

        std::cout << "\nIterando con const_iterator:" << std::endl;
        const MutantStack<int> const_mstack = mstack;
        for (MutantStack<int>::const_iterator cit = const_mstack.begin(); cit != const_mstack.end(); ++cit) {
            std::cout << *cit << std::endl;
        }

        std::cout << "\nIterando con const_reverse_iterator:" << std::endl;
        for (MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin(); crit != const_mstack.rend(); ++crit) {
            std::cout << *crit << std::endl;
        }
    }

    {
        std::cout << "===== Test Subject with MutantStack =====" << std::endl;

        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);

        std::cout << "\n===== Test Subject with std::list =====" << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator lit = lst.begin();
        std::list<int>::iterator lite = lst.end();
        ++lit;
        --lit;
        while (lit != lite)
        {
            std::cout << *lit << std::endl;
            ++lit;
        }
    }

    return 0;
}
