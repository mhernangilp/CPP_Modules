#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try {
		if (argc != 2) {
			throw(std::string) "invalid number of arguments";
		}
		RPN rpn(argv[1]);

	} catch (const std::string &error) {
		std::cout << "Error: " << error << std::endl;
        return 1;
	}
    return 0;
}