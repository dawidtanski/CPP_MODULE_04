#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

static void sep(const char* title) {
std::cout << "\n=== " << title << " ===" << std::endl;
}
int main()
{


//////////////////////////////////////
// std::cout << "-----Basic tests from script-------------" << std::endl;
// IMateriaSource* src = new MateriaSource();
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
std::cout << "-----Additional tests-------------" << std::endl;
sep("1. Spec example (ice & cure)");
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
    }

    sep("2. Deep copy (copy ctor)");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());

        Character a("A");
        AMateria* tmp = src->createMateria("ice");
        a.equip(tmp);

        Character b(a); // copy ctor deep copy
        // delete a; // if a is on stack, do not delete; here we let it go out of scope
        Character target("Target");
        b.use(0, target); // should still work (deep copy)
        delete src;
    }

    sep("3. Deep copy (operator=)");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());

        Character a("A2");
        AMateria* tmp = src->createMateria("cure");
        a.equip(tmp);

        Character b("B2");
        b = a; // operator= deep copy required
        Character t("T2");
        b.use(0, t);
        delete src;
    }

    sep("4. Wrong: sharing the same AMateria ptr between two Characters (UNSAFE - commented)");
    {
        // The following example is intentionally left commented to avoid crash.
        // Uncomment to see the double-delete UB (unsafe):
        /*
        AMateria* shared = new Ice();
        Character a("A3");
        a.equip(shared);
        Character b("B3");
        b.equip(shared); // now both a and b own the same pointer -> double delete
        // you will likely crash here when a and b destructors run (double delete)
        */
        std::cout << "(example commented out to avoid crash) If you create one AMateria and equip the same pointer to two characters, both will later try to delete it -> UB." << std::endl;
    }

    sep("5. Correct: createMateria for each equip -> no sharing and no double-delete");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        Character a("A4");
        Character b("B4");
        AMateria* t1 = src->createMateria("ice"); // clone
        AMateria* t2 = src->createMateria("ice"); // clone again
        a.equip(t1);
        b.equip(t2);
        Character target("T4");
        a.use(0, target);
        b.use(0, target);
        delete src;
    }

    sep("6. Unequip -> floor");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Cure());
        Character me("meUF");
        AMateria* t = src->createMateria("cure");
        me.equip(t);
        me.use(0, me); // heal itself
        me.unequip(0); // moves to floor, inventory slot becomes NULL
        me.use(0, me); // nothing should happen
        // destructor of Character will delete items in floor; no leaks
        delete src;
    }

    sep("7. Full inventory handling (equip 5 times)");
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        Character me("fullInv");
        AMateria* t;
        for (int i = 0; i < 5; ++i) {
            t = src->createMateria("ice");
            me.equip(t); // only first 4 should be equipped
        }
        Character target("TargetFull");
        me.use(3, target); // should be Woof/Meow or Ice use
        me.use(4, target); // out of bounds / nothing or invalid -> nothing
        delete src;
    }

    sep("8. createMateria unknown type returns NULL");
    {
        IMateriaSource* src = new MateriaSource();
        AMateria* unknown = src->createMateria("unknown");
        if (!unknown)
            std::cout << "createMateria returned NULL for unknown type (OK)" << std::endl;
        else {
            std::cout << "createMateria returned non-NULL for unknown type (unexpected)" << std::endl;
            delete unknown;
        }
        delete src;
    }

    sep("9. MateriaSource deep copy test");
    {
        MateriaSource a; // concrete
        a.learnMateria(new Ice());
        a.learnMateria(new Cure());
        MateriaSource b(a); // copy ctor deep should clone templates
        AMateria* mi = b.createMateria("ice");
        Character c("UseFromCopy");
        c.equip(mi);
        c.use(0, c);
    }

    sep("10. AMateria::clone returns different pointer and same type");
    {
        Ice i;
        AMateria* clone = i.clone();
        std::cout << "Two pointers differ? " << (clone != &i ? "Yes" : "No") << std::endl;
        std::cout << "clone->getType() == \"ice\"? " << (clone->getType() == std::string("ice") ? "Yes" : "No") << std::endl;
        delete clone;
    }

    std::cout << "\nAll tests finished. Run valgrind for memory checks.\n" << std::endl;
return 0;
}