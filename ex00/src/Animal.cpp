/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:41:18 by dtanski           #+#    #+#             */
/*   Updated: 2025/07/31 18:05:06 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	std::cout << "Default animal constructor" << std::endl;
}

Animal::Animal(std::string animalType) : type(animalType)
{
	std::cout << "Animal constructor with type: " << type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal &src) : type(src.type){}

Animal& Animal::operator=(const Animal &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		type = src.type;
	}
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Doesn't know this animal" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}