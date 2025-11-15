#pragma once

#include <iostream>

class Brain{

	private:
			std::string ideas[100];
	public:
			Brain();
			~Brain();
			Brain (const Brain &other);
			Brain& operator=(const Brain &other);

			// void setIdeas(std::string idea);
			// void getIdeas();
};
