#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
    std::cout << PURPLE << "---Increment Taxes---" << RESET << std::endl;
    try {
        Form incrementTaxes("IncrementTaxes", 0, 8);    
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }
    Form incrementTaxes("IncremetTaxes", 30, 8);
    std::cout << incrementTaxes << std::endl;

    Bureaucrat juan("Juan", 31);
    std::cout << juan << std::endl;
    try {
        incrementTaxes.beSigned(juan);
    } catch (std::exception &e) {
        std::cerr << RED << "Error. " << e.what() << RESET << std::endl;
    }
    juan.incrementGrade();
    std::cout << juan << std::endl;
    incrementTaxes.beSigned(juan);
    std::cout << incrementTaxes << std::endl;

    return 0;
}