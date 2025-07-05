#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie (std::string name) : name(name)
{
	std::cout << "Zombie " << name << " creado." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie sin nombre creado." << std::endl;
}