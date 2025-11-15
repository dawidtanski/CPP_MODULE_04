#pragma once

#include <iostream>

class Animal{

	protected:
			std::string type;
	public:

			Animal();
			// Animal(std::string type);
			virtual ~Animal();
			Animal (const Animal &other);
			Animal& operator=(const Animal &other);
			virtual void makeSound() const = 0;

			const std::string&	getType() const;
			// void	setType()
};