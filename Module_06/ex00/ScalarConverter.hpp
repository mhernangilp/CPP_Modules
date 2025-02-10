#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter {
    public:
        static void convert(const std::string& str);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& original);
        ScalarConverter& operator=(const ScalarConverter& original);
        ~ScalarConverter();

        static void convertFromChar(const std::string& str);
        static void convertFromInt(const std::string& str);
        static void convertFromFloat(const std::string& str);
        static void convertFromDouble(const std::string& str);
};

#endif