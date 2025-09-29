/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:10:14 by dtanski           #+#    #+#             */
/*   Updated: 2025/07/31 17:56:18 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal();
		Animal(std::string type);
		~Animal();
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual void	makeSound() const;
		std::string	getType() const;
};


#endif