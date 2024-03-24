#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    FlagTrap a("Jose");
    ScavTrap b("Alberto");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("Juan");
    a.beRepaired(3);
    a.takeDamage(15);
    a.highFivesGuys();

    b.takeDamage(5);
    b.beRepaired(1);
    b.attack("Juan");
    b.beRepaired(3);
    b.takeDamage(15);
    b.guardGate();

    return (0);
}