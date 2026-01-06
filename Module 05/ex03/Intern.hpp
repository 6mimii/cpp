#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		Form* createShrubbery(std::string target);
		Form* createRobotomy(std::string target);
		Form* createPresidential(std::string target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		Form* makeForm(std::string formName, std::string target);
};

#endif
