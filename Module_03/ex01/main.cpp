#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("Jose");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("Juan");
    a.beRepaired(3);
    a.takeDamage(15);
    a.guardGate();

    return (0);
}