#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{

	private:
			AMateria* _templates[4];
			void	clear();
			void	copyFrom(const MateriaSource &other);
	
	public:
			MateriaSource();
			~MateriaSource();
			MateriaSource(const MateriaSource&  other);
			MateriaSource& operator=(const MateriaSource& other);
			
			void		learnMateria(AMateria *m);
			AMateria*	createMateria(std::string const &type);
};