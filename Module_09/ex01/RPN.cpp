#include "RPN.hpp"

RPN::RPN() : result(0) {}

RPN::RPN(const std::string& rpn) : result(0) {
    for (size_t i = 0; i < rpn.size(); ++i) {
        char c = rpn[i];
        if (std::isspace(c))
            continue;

        validateToken(rpn, i);

        if (std::isdigit(c)) {
            stack.push(static_cast<double>(c - '0'));
        } else if (isOperator(c)) {
            applyOperator(c);
        }
    }

    if (stack.size() != 1) {
        throw(std::string) "invalid expression, result stack not size 1";
    }

    std::cout << stack.top() << std::endl;
}

RPN::RPN(const RPN& original) : result(original.result), stack(original.stack) {}

RPN& RPN::operator=(const RPN& original) {
    if (this != &original) {
        result = original.result;
        stack = original.stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::validateToken(const std::string& rpn, size_t index) const {
    char c = rpn[index];
    if (!std::isdigit(c) && !std::isspace(c) && !isOperator(c)) {
        throw(std::string) "invalid character";
    }
    if (std::isdigit(c) && (index + 1 < rpn.size() && !std::isspace(rpn[index + 1]))) {
        throw(std::string) "digits must be separated by spaces";
    }
    if (isOperator(c) && stack.size() < 2) {
        throw(std::string) "not enough operands for operation";
    }
}

void RPN::applyOperator(char op) {
    double second = stack.top();
    stack.pop();
    double first = stack.top();
    stack.pop();

    switch (op) {
        case '+': result = first + second; break;
        case '-': result = first - second; break;
        case '*': result = first * second; break;
        case '/':
            if (second == 0)
                throw(std::string) "division by zero";
            result = first / second;
            break;
    }
    stack.push(result);
}

