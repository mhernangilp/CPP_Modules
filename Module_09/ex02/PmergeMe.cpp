#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& original) { (void) original; }

PmergeMe& PmergeMe::operator=(const PmergeMe& original) { (void) original; return *this; }

PmergeMe::~PmergeMe() {}

void PmergeMe::mergeInsertSortVector(std::vector<int> &container, int start, int end) {
    if (start >= end)
        return;

    if (end - start < 10) {
        insertSortVector(container, start, end);
        return;
    }

    int mid = start + (end - start) / 2;
    mergeInsertSortVector(container, start, mid);
    mergeInsertSortVector(container, mid + 1, end);
    mergeSortVector(container, start, mid, end);
}

void PmergeMe::mergeSortVector(std::vector<int> &container, int start, int mid, int end) {
    std::vector<int> left(container.begin() + start, container.begin() + mid + 1);
    std::vector<int> right(container.begin() + mid + 1, container.begin() + end + 1);

    long unsigned int i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < left.size())
        container[k++] = left[i++];

    while (j < right.size())
        container[k++] = right[j++];
}

void PmergeMe::insertSortVector(std::vector<int> &container, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = container[i];
        int j = i - 1;

        while (j >= start && container[j] > key) {
            container[j + 1] = container[j];
            --j;
        }

        container[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &container, int start, int end) {
    if (start >= end)
        return;

    if (end - start < 10) {
        insertSortDeque(container, start, end);
        return;
    }

    int mid = start + (end - start) / 2;
    mergeInsertSortDeque(container, start, mid);
    mergeInsertSortDeque(container, mid + 1, end);
    mergeSortDeque(container, start, mid, end);
}

void PmergeMe::mergeSortDeque(std::deque<int> &container, int start, int mid, int end) {
    std::deque<int> left(container.begin() + start, container.begin() + mid + 1);
    std::deque<int> right(container.begin() + mid + 1, container.begin() + end + 1);

    long unsigned int i = 0, j = 0, k = start;

    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
            container[k++] = left[i++];
        else
            container[k++] = right[j++];
    }

    while (i < left.size())
        container[k++] = left[i++];

    while (j < right.size())
        container[k++] = right[j++];
}

void PmergeMe::insertSortDeque(std::deque<int> &container, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = container[i];
        int j = i - 1;

        while (j >= start && container[j] > key) {
            container[j + 1] = container[j];
            --j;
        }

        container[j + 1] = key;
    }
}

void PmergeMe::runVector(std::vector<int> &container) {
    mergeInsertSortVector(container, 0, container.size() - 1);
}

void PmergeMe::runDeque(std::deque<int> &container) {
    mergeInsertSortDeque(container, 0, container.size() - 1);
}

void print(const std::vector<int> &vec, const std::deque<int> &deq)
{
    static int i = 0;
    const std::string state = (i == 0) ? "before" : "after";

    std::cout << MAG << "Vector " << state << " : " << ((i == 0) ? BEFORE : AFTER);
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << MAG << "Deque  " << state << " : " << ((i == 0) ? BEFORE : AFTER);
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    ++i;
}

void calculateTime(std::vector<int> &vContainer, std::deque<int> &dContainer, double &vecTime, double &deqTime)
{
    std::clock_t start, end;

    start = std::clock();
    PmergeMe::runVector(vContainer);
    end = std::clock();
    vecTime = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;

    start = std::clock();
    PmergeMe::runDeque(dContainer);
    end = std::clock();
    deqTime = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
}