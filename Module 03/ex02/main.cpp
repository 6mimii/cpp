#include "FragTrap.hpp"
#include <iostream>

int main() {
    FragTrap frag("Fraggy");
    frag.attack("Target1");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.highFiveGuys();
    return 0;
}