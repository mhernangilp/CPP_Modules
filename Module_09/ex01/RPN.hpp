#ifndef RPN_H
#define RPN_H

#include <string>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <sstream>

class RPN {
    private:
        double result;
        std::stack<double> stack;

        bool isOperator(char c) const;
        void validateToken(const std::string& rpn, size_t index) const;
        void applyOperator(char op);

    public:
        RPN();
        RPN(const std::string& rpn);
        RPN(const RPN& original);
        RPN& operator=(const RPN& original);
        ~RPN();
};

#endif