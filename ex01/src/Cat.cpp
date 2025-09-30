#include "../inc/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
	brain = new Brain;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other):Animal(other){
	brain = new Brain(*other.brain);
	std::cout << "Cat copy conrtuctor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout << "Cat copy assignment operator called" << std::endl;
		*brain = *other.brain;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}