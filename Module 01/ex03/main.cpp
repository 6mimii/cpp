#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main ()
{
	{		
		Weapon pistol("AK47");
		HumanA Ñengo("Ñengo", pistol);
		Ñengo.attack();
		pistol.setType("Glock");
		Ñengo.attack();
	}
	{
		Weapon stick("Glizzy");
		HumanB Chimi("Chimi");
		Chimi.attack();
		Chimi.setWeapon(stick);
		Chimi.attack();
		stick.setType("Colta");
		Chimi.attack();		
	}
	return 0;
}