#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
	std::cout << "ClapTrap " << _name << " can't attack because it's out of hit points!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't attack because it's out of energy points!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
				<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already out of hit points!" << std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0) _hitPoints = 0; // Evitar valores negativos
	std::cout << "ClapTrap " << _name << " takes " << amount
				<< " points of damage! Remaining hit points: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't be repaired because it's out of hit points!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name << " can't be repaired because it's out of energy points!" << std::endl;
		return;
    }
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount
			  << " hit points! Current hit points: " << _hitPoints << std::endl;
}
