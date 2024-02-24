#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    std::string str;

    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return (1);
    }
    str.assign(argv[1]);
    harl.complain(str);
    return (0);
}