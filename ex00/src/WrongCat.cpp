/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:43:21 by dtanski           #+#    #+#             */
/*   Updated: 2025/07/31 18:44:38 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "Default animal constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &src)
{
	if (this != &src)
	{
		WrongAnimal::operator=(src);
		std::cout << "WrongCat assignment operator called" << std::endl;
	}
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!" << std::endl;
} 