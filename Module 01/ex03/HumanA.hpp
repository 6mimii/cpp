#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
	std::string name;
	Weapon &weapon; //referencia al arma siempre la tiene

	public:
	HumanA (const std::string &name, Weapon &weapon);
	void attack() const;

};

#endif