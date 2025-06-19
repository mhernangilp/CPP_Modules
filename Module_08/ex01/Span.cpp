#include "Span.hpp"

Span::Span() : max(0) {}

Span::Span(unsigned int N) : max(N) {}

Span::Span(const Span & original) : values(original.values), max(original.max) {}

Span::~Span() {}

Span &Span::operator=(const Span & original) {
    if (this != &original) {
        max = original.max;
        values = original.values;
    }
    return *this;
}

unsigned int Span::getMax() const {
    return max;
}

const std::vector<int> &Span::getValues() const {
    return values;
}

void    Span::addNumber(int n) {
    if (values.size() < (unsigned long)max)
        values.push_back(n);
    else
        throw Span::Full();
    std::sort(values.begin(), values.end());
}

int Span::shortestSpan() {
    if (values.size() <= 1)
        throw Span::CantSpan();

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < values.size(); ++i) {
        int diff = values[i] - values[i - 1];
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}

int     Span::longestSpan() {
    if (values.size() <= 1)
        throw Span::CantSpan();

    return (values[values.size() - 1] - values[0]);
}
