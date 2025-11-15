#pragma once

#include "../inc/ICharacter.hpp"
#include <list>

class AMateria;

class Character: public ICharacter{
	
	private:
			std::string _name;
			AMateria* _inventory[4];
			std::list<AMateria*> _floor;
			// List started empty by defalut. No need to zeroing

	public:
			Character(const std::string& name);
			~Character();
			Character(const Character &other);
			Character& operator=(const Character &other);

			std::string const & getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);

};