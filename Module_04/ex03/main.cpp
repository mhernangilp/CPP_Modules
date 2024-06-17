#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;

    std::cout << "\n------More tests------\n" << std::endl;

    src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    me = new Character("me");
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("something");
    me->equip(tmp);

    Character* juan = new Character("juan");

    me->use(1, *juan);
    me->unequip(1);
    me->use(1, *juan);
    me->use(2, *juan);

    tmp = src->createMateria("ice");
    juan->equip(tmp);

    Character* juan2 = new Character(*juan);
    
    juan2->use(0, *me);

    delete juan2;
    delete juan;
    delete me;
    delete src;
    
    return 0;
}