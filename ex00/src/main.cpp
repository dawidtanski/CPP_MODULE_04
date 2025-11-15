/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanski <dtanski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 21:08:08 by dtanski           #+#    #+#             */
/*   Updated: 2025/11/15 17:05:27 by dtanski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

// Wrong one
const WrongAnimal* wr = new WrongAnimal();


std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
// Wrong one
std::cout << wr->getType() << " " << std::endl;
wr->makeSound();

// Cleaning memory
delete meta;
delete j;
delete i;
delete wr;

return 0;
}