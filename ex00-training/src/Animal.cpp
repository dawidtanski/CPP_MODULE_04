#include "../inc/Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
}

// Animal::Animal(std::string type){
// 	std::cout << "Animal type constructor called" << std::endl;
// 	type = type;
// }

Animal::~Animal(){
	std::cout << "Animal default destructor called" << std::cout;
}

Animal::Animal(const Animal &other){
	type = other.type;
}

Animal& Animal::operator=(const Animal &other){
	if (this != &other)
	{	
		type = other.type;
	}
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal sound" << std::endl;
}

const std::string&	Animal::getType() const{
	return type;
}