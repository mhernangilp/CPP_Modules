#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <ctime>
#include <sstream>

#define BEFORE  "\e[0;31m"
#define AFTER  "\e[0;32m"
#define MAG "\e[0;35m"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class PmergeMe {
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& original);
        PmergeMe& operator=(const PmergeMe& original);
        ~PmergeMe();
        
        static void mergeInsertSortVector(std::vector<int> &container, int start, int end);
        static void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
        static void insertSortVector(std::vector<int> &container, int start, int end);

        static void mergeInsertSortDeque(std::deque<int> &container, int start, int end);
        static void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
        static void insertSortDeque(std::deque<int> &container, int start, int end);
        
        static void runVector(std::vector<int> &container);
        static void runDeque(std::deque<int> &container);
};

void print(const std::vector<int> &vec, const std::deque<int> &deq);
void calculateTime(std::vector<int> &vContainer, std::deque<int> &dContainer, double &vecTime, double &deqTime);

#endif