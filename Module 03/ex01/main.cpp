#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main () {
	ScavTrap scav("Scavy");

	scav.attack("Target1");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.attack("Target2");

	return 0;
}