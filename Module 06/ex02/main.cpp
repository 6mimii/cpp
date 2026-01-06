#include "Base.hpp"
#include "Classes.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
	int i = std::rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception&) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception&) {}
}

int main() {
	std::srand(std::time(NULL));

	std::cout << "Generating random object..." << std::endl;
	Base* p = generate();
	
	std::cout << "Identify by pointer: ";
	identify(p);

	std::cout << "Identify by reference: ";
	identify(*p);

	delete p;
	return 0;
}
