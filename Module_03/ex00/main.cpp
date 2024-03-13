#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Jose");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("Juan");
    a.beRepaired(3);
    a.takeDamage(15);

    return (0);
}