#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"


Character::Character(const std::string& name){
	_name = name;
	for (int i = 0; i < 4; i++){
		_inventory[i] = 0;
	}
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (_inventory[i]){
			delete _inventory[i];
			_inventory[i] = 0;
		}
	}
	for (std::list<AMateria*>::iterator it = _floor.begin(); it != _floor.end(); ++it){
		delete *it;
	}
};

Character::Character(const Character &other){
	_name = other._name;
	// Cloning character's inventory
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
	// Cloning character's floor
	for (std::list<AMateria*>::const_iterator it = other._floor.begin(); it != other._floor.end(); ++it){
		AMateria* m = *it;
		_floor.push_back(m ? m->clone() : NULL);
	}
}

Character& Character::operator=(const Character &other){
	if (this != &other){
		// Clearing target's inventory
		for (int i = 0; i < 4; i++){
			if (_inventory[i]){
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		// Clearing target's floor
		for (std::list<AMateria*>::iterator it = _floor.begin(); it != _floor.end(); ++it)
			delete *it;
		_floor.clear();
		// Copying name
		_name = other._name;
		// Copying inventory from src(other) to target()
		for (int i = 0; i < 4; i++){
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}
		// Copying floor from src(other) to target()
		for (std::list<AMateria*>::const_iterator it = other._floor.begin(); it != other._floor.end(); ++it){
			AMateria* m = *it;
			_floor.push_back(m ? m->clone() : NULL);
		}
	}
	return *this;
}

std::string const& Character:: getName() const{
	return _name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4; i++){
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m->clone();
			delete m;
			// std::cout << m->getType() << "equipped" << std::endl;
			return;
		}
	}
	delete m;
}

void	Character::unequip(int idx){
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
	{
		_floor.push_front(_inventory[idx]);
		_inventory[idx] = NULL;
		// std::cout << "Item number " << idx << " dropped." << std::endl;
	}
	else
	{
		// std::cout << "Wrong item number" << std::endl;
		return;
	}
}

void	Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx >= 4)
		return;
	AMateria* m = _inventory[idx];
	if (!m)
		return;
	m->use(target);
}