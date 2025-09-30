#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"


int main()
{
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
	Dog d; d = d;           // nic złego nie powinno się wydarzyć
	Cat c; c = c;
}

Animal* animals_str[10];

for (int k = 0; k < 5; k++)
	animals_str[k] = new Dog();

for (int k = 5; k < 10; k++)
	animals_str[k] = new Cat();

for (int k = 0; k < 10; k++)
	delete animals_str[k];

return 0;
}