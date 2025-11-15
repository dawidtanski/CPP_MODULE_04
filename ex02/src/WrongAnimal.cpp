/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:38:41 by dtanski           #+#    #+#             */
/*   Updated: 2025/07/31 18:41:33 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default animal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string animalType) : type(animalType)
{
	std::cout << "WrongAnimal constructor with type: " << type << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type){}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		type = src.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}