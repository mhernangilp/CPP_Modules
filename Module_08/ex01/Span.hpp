#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

class Span {
    private:
        std::vector<int>    values;
        unsigned int        max;
    
    public:
        Span();
        Span(unsigned int N);
        Span(const Span & original);
        ~Span();
        Span &operator=(const Span & original);

        unsigned int getMax() const;
        const std::vector<int> &getValues() const;

        void    addNumber(int n);
        int     shortestSpan();
        int     longestSpan();

        template <class Iterator>
        void addNumber(Iterator begin, Iterator end) {
            if (static_cast<size_t>(std::distance(begin, end)) + this->values.size() > max)
                throw(NotEnoughSpace());
            std::copy(begin, end, std::back_inserter(this->values));
            std::sort(this->values.begin(), this->values.end());
        }

        class NotEnoughSpace : public std::exception
        {
            virtual const char* what() const throw() {
                return ("Not enough space in the span to add the range.");
            }
        };

        class Full : public std::exception
        {
            virtual const char* what() const throw() {
                return ("Span is full.");
            }
        };

        class CantSpan : public std::exception
        {
            virtual const char* what() const throw() {
                return ("Span doesn't have enough values to do a span.");
            }
        };
};

#endif