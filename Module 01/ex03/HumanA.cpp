#include "HumanA.hpp"
#include <iostream>

//el constructor inicializa nombre y referencia del arma
HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack() const {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}