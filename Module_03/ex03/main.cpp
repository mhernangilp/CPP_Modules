#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Bozo("Bozo");
    DiamondTrap Rato("Rato");

    std::cout << std::endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    std::cout << std::endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    std::cout << std::endl;

    Rato.attack("Bozo");
    Bozo.takeDamage(30);

    std::cout << std::endl;

    Rato.guardGate();
    Rato.highFivesGuys();

    std::cout << std::endl;

    Rato.whoAmI();

    std::cout << std::endl;

    return 0;
}