#include "../inc/Dog.hpp"

Dog::Dog(){
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	brain = new Brain;
}

Dog::~Dog(){
	std::cout << "Dog default destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other):Animal(other){
	std::cout << "Dog copy conrtuctor called." << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other)
	{
		Animal::operator=(other);
        std::cout << "Dog copy assignment operator called" << std::endl;
		*brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound() const{
	std::cout << "Woof!" << std::endl;
}