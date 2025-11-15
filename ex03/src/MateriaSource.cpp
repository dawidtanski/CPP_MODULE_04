#include "../inc/AMateria.hpp"
#include "../inc/MateriaSource.hpp"

void	MateriaSource::clear(){
	for(int i = 0; i < 4; i++){
		delete _templates[i];
		_templates[i] = 0;
	}
}

void	MateriaSource::copyFrom(const MateriaSource &other){
	for(int i = 0; i < 4; i++){
		_templates[i] = other._templates[i] ? other._templates[i]->clone() : 0;
	}
}

MateriaSource::MateriaSource(){
	for(int i = 0; i < 4; i++){
		_templates[i] = 0;
	}
}

MateriaSource::~MateriaSource(){
	clear();
}

MateriaSource::MateriaSource(const MateriaSource& other){
	for(int i = 0; i < 4; i++){
		_templates[i] = 0;
	}
	copyFrom(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
	if (this != &other)
	{
		clear();
		copyFrom(other);
	}
	return *this;
}


void	MateriaSource::learnMateria(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++){
		if (_templates[i] == 0){
			_templates[i] = m->clone();
			delete m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if(_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return (0);
}