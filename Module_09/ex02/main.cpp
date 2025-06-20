#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw "provide at least one integer as argument.";

        std::vector<int> vec;
        std::deque<int> deq;
        double vectorSortingTime;
        double dequeSortingTime;

        for (int i = 1; i < argc; ++i) {
            std::stringstream ss(argv[i]);
            int number;
            if (!(ss >> number) || !ss.eof())
                throw "arguments must be integers.";
            if (number < 0)
                throw "negative numbers are not allowed.";

            vec.push_back(number);
            deq.push_back(number);
        }

        std::cout << std::endl;
        print(vec, deq);

        calculateTime(vec, deq, vectorSortingTime, dequeSortingTime);

        std::cout << std::endl;
        print(vec, deq);

        std::cout << std::endl
                  << YELLOW << "Time to process a range of " << (argc - 1)
                  << " elements with std::vector : " << vectorSortingTime << " us" << std::endl
                  << "Time to process a range of " << (argc - 1)
                  << " elements with std::deque  : " << dequeSortingTime << " us"
                  << RESET << std::endl;
    } catch (const char *errorMsg) {
        std::cerr << RED << "Error: " << errorMsg << RESET << std::endl;
        return 1;
    }

    return 0;
}
