#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice: public AMateria{
	
	public:
		Ice();
		~Ice();
		Ice(const Ice &other);
		Ice& operator=(const Ice &other);
		
		AMateria* clone() const;
		void use(ICharacter& target);
};