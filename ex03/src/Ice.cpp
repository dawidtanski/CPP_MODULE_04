#include "../inc/Ice.hpp"
#include "../inc/ICharacter.hpp"

Ice::Ice():AMateria("ice"){
	this->_type = "ice";
}

Ice::~Ice(){}

Ice::Ice(const Ice &other):AMateria(other){
	_type = other._type;
}

Ice& Ice::operator=(const Ice &other){
	if (this != &other){
	}
	return *this;
}

AMateria* Ice::clone() const{
	return new Ice(*this);
}

void	Ice::use(ICharacter &target){
	std::cout <<  "* shoots an ice bolt at " << target.getName()  << " *" << std::endl;
}