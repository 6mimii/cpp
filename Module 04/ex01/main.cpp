#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream> 

int main()
{
	std::cout << "=== TEST DEL ARRAY DE ANIMALES ===" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize / 2; i++) {
		animals[i] = new Dog();
	}

	for (int i = arraySize / 2; i < arraySize; i++) {
		animals[i] = new Cat();
	}

	std::cout << "\n--- Borrando los animales... ---" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		delete animals[i];
	}

	std::cout << "\n=== TEST DE COPIA PROFUNDA ===" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;  
	}
	return 0;
}
