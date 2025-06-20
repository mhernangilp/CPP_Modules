#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc < 2)
            throw std::string("could not open file.");
        if (argc > 2)
            throw std::string("too many arguments.");

        BitcoinExchange bitcoin;
        std::string argv1(argv[1]);
        bitcoin.handleInputFile(argv1);
        
    } catch (const std::string &error) {
        std::cerr << "Error: " << error << std::endl;
        return 1;
    }

    return 0;
}