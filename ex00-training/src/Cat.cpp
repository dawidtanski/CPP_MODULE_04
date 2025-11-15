#include "../inc/Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat(){
	std::cout << std::cout << "Animal default destructor called" << std::endl;
}

Cat::Cat(const Cat &other):Animal(other){
	std::cout << "Cat copy conrtuctor called." << std::endl;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other)
	{
 		Animal::operator=(other);
		std::cout << "Cat copy assignment operator called" << std::endl;
	}
	return *this;
}

void Cat::makeSound() const{
	std::cout << "Meow!" << std::endl;
}