#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

Cure::Cure():AMateria("cure"){
	this->_type = "cure";
}

Cure::~Cure(){}

Cure::Cure(const Cure &other):AMateria(other){
	_type = other._type;
}

Cure& Cure::operator=(const Cure &other){
	if (this != &other){
	}
	return *this;
}

AMateria* Cure::clone() const{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target){
	std::cout <<  "* heals " << target.getName() << "’s wounds *" << std::endl;
}