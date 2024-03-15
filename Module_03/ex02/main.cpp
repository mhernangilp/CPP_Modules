#include "ClapTrap.hpp"
#include "FlagTrap.hpp"

int main(void)
{
    FlagTrap a("Jose");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("Juan");
    a.beRepaired(3);
    a.takeDamage(15);
    a.highFivesGuys();

    return (0);
}