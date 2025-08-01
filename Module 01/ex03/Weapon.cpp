#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {} //inicializar

const std::string &Weapon::getType() const { // leer valor del atri. type 
	return this->type;
}

void Weapon::setType(const std::string &type) { // cambiar el valor del type
	this->type = type;
}

