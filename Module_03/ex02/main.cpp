#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap a("Jose");

    a.takeDamage(5);
    a.beRepaired(1);
    a.attack("Juan");
    a.beRepaired(3);
    a.takeDamage(15);
    a.highFivesGuys();

    return (0);
}