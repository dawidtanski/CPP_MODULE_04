#include "../inc/Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain default destructor called" << std::endl;
}

Brain::Brain(const Brain &other){
	std::cout << "Brain copy conrtuctor called." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
        std::cout << "Brain copy assignment operator called" << std::endl;
	}
	return *this;
}

// void Brain::setIdeas(std::string idea){
// 	for (int i = 0; i < 100; i++)
// 		ideas[i] = idea;
// }

// void	Brain::getIdeas()
// {
// 	std::cout << ideas[0] << std::endl;
// }