#include "Fixed.hpp"

int main() {
			Fixed a;          // Llama al constructor por defecto
			Fixed b(42);      // Llama al constructor que toma un entero
			Fixed c(42.42f);  // Llama al constructor que toma un flotante
		
			std::cout << "b as float: " << b.toFloat() << std::endl;
			std::cout << "b as int: " << b.toInt() << std::endl;
		
			std::cout << "c as float: " << c.toFloat() << std::endl;
			std::cout << "c as int: " << c.toInt() << std::endl;
		
			std::cout << "a: " << a << std::endl;
			std::cout << "b: " << b << std::endl;
			std::cout << "c: " << c << std::endl;
		
			return 0;
		}