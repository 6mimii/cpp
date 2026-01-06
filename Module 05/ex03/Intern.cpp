#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Form* Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	Form* (Intern::*creators[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(target);
		}
	}

	std::cout << "Error: Form name '" << formName << "' does not exist" << std::endl;
	return NULL;
}
