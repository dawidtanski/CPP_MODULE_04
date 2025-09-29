/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:28:45 by dtanski           #+#    #+#             */
/*   Updated: 2025/07/31 17:58:42 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		// Cat(std::string type);
		~Cat();
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		void	makeSound() const;
};


#endif