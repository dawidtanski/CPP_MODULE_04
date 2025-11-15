#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"


Character::Character(const std::string& name){
	_name = name;
	for (int i = 0; i <= 3; i++){
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
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : 0;
}

Character& Character::operator=(const Character &other){
	if (this != &other){
		for (int i = 0; i <= 3; i++){
			delete _inventory[i];
			_inventory[i] = 0;
		}
		_name = other._name;
		for (int i = 0; i <= 3; i++){
			_inventory[i] = other._inventory[i];
		}
	}
	return *this;
}

std::string const& Character:: getName() const{
	return _name;
}

void	Character::equip(AMateria* m)
{
	for(int i = 0; i <= 3; i++){
		if (_inventory[i] == 0)
		{
			_inventory[i] = m;
			// std::cout << m->getType() << "equipped" << std::endl;
			break;
		}
	}
}

void	Character::unequip(int idx){
	if (idx <= 3 && idx >= 0)
	{
		_floor.push_front(_inventory[idx]);
		_inventory[idx] = 0;
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