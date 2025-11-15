#include "../inc/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog(){
	std::cout << std::cout << "Animal default destructor called" << std::endl;
}

Dog::Dog(const Dog &other):Animal(other){
	std::cout << "Dog copy conrtuctor called." << std::endl;
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other)
	{
		Animal::operator=(other);
        std::cout << "Dog copy assignment operator called" << std::endl;
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof!" << std::endl;
}