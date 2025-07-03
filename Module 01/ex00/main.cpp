#include "Zombie.hpp"

int main ()
{
	Zombie* heapZombie = newZombie("AMARION");
	heapZombie->announce();
	delete heapZombie;
	randomChump("KENDO KAPONI");
	return 0;
}