#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(15);
	clap.beRepaired(10);
	clap.takeDamage(10);
	clap.attack("Target");
	clap.beRepaired(5);
    return 0;
}