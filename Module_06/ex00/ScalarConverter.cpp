#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& original) { (void)original; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& original) { (void)original; return *this; }
ScalarConverter::~ScalarConverter() {}

bool isPseudoLiteral(const std::string& str) {
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (str == "nan" || str == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (str == "+inf" || str == "+inff") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return true;
    }
    return false;
}

bool isChar(const std::string& str) {
    return str.length() == 1 && ((str[0] >= 32 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 126));
}

bool isInt(const std::string& str) {
    if (str.length() == 0)
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i == str.length())
        return false;
    for (; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isFloat(const std::string& str) {
    if (str.length() < 4)
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (str.length() < 5)
            return false;
    }
    if (i == str.length())
        return false;
    for (; i < str.length(); i++) {
        if (str[i] == '.')
            break;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    i++;
    for (; i < str.length() - 1; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

bool isDouble(const std::string& str) {
    if (str.length() < 3)
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
        if (str.length() < 4)
            return false;
    }
    if (i == str.length())
        return false;
    for (; i < str.length(); i++) {
        if (str[i] == '.')
            break;
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    i++;
    for (; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

void ScalarConverter::convertFromChar(const std::string& str) {
    char c = str[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(const std::string& str) {
    char* endPtr;
    long int i = strtol(str.c_str(), &endPtr, 10);

    if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    if (i > INT_MAX || i < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string& str) {
    char* endPtr;
    float f = strtof(str.c_str(), &endPtr);

    if (f < 32 || f > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    if (f == static_cast<int>(f)) {
        std::cout << "float: " << f << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(const std::string& str) {
    char* endPtr;
    double d = strtod(str.c_str(), &endPtr);

    if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (d == static_cast<int>(d)) {
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convert(const std::string& str) {
    if (isPseudoLiteral(str))
        return;
    if (isChar(str))
        convertFromChar(str);
    else if (isInt(str))
        convertFromInt(str);
    else if (isFloat(str))
        convertFromFloat(str);
    else if (isDouble(str))
        convertFromDouble(str);
    else {
        std::cerr << "Error: Invalid literal." << std::endl;
        return;
    }
}
