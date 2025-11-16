#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"


int main()
{

// Testing abstract class
std::cout << "Testing abstract class" << std::endl;
// Animal x;  // ← Cannot instantiate abstract class (compilation error)

const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

/////////////////////////
std::cout << "\n=== Deep copy tests (copy ctor and copy assignment) ===" << std::endl;
{
	std::cout << "--- Dog copies ---" << std::endl;
	Dog d1;
	Dog d2(d1);
	Dog d3;
	d3 = d1;
	std::cout << "--- End Dog scope ---" << std::endl;
}
// Expected to see 3 dog and brain destructors
////////////////////////

std::cout << "\n=== Deep copy tests (copy ctor and copy assignment) ===" << std::endl;
{
	std::cout << "--- Cat copies ---" << std::endl;
	Cat c1;
	Cat c2(c1);
	Cat c3;
	c3 = c1;
	std::cout << "--- End Cat scope ---" << std::endl;
}

// Self assignment safety
std::cout << "\n=== Self-assignment safety ===" << std::endl;
{
	Dog d; d = d;           // Nothing wrong should happens
	Cat c; c = c;
}

Animal* animals_str[10];

for (int k = 0; k < 5; k++)
	animals_str[k] = new Dog();

for (int k = 5; k < 10; k++)
	animals_str[k] = new Cat();

for (int k = 0; k < 10; k++)
	delete animals_str[k];

// Test virtual makeSound() through polymorphism
std::cout << "\n=== Polymorphic makeSound() test ===" << std::endl;
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	
	dog->makeSound();  // Should print Dog sound
	cat->makeSound();  // Should print Cat sound
	
	delete dog;
	delete cat;
}

return 0;
}