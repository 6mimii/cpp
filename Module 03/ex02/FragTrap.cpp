#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is created!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;

}

void FragTrap::highFiveGuys() {
		std::cout << "FragTrap " << _name << " request a high five!" << std::endl;
	}