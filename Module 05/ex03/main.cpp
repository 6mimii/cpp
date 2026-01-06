#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	std::cout << "========== TEST 1: Creating valid forms ==========" << std::endl;
	{
		Intern someRandomIntern;
		Form* form1;
		Form* form2;
		Form* form3;

		form1 = someRandomIntern.makeForm("shrubbery creation", "home");
		form2 = someRandomIntern.makeForm("robotomy request", "Bender");
		form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		std::cout << "\n--- Testing created forms ---" << std::endl;
		if (form1) {
			std::cout << *form1 << std::endl;
			delete form1;
		}
		if (form2) {
			std::cout << *form2 << std::endl;
			delete form2;
		}
		if (form3) {
			std::cout << *form3 << std::endl;
			delete form3;
		}
	}

	std::cout << "\n========== TEST 2: Invalid form name ==========" << std::endl;
	{
		Intern someRandomIntern;
		Form* form;

		form = someRandomIntern.makeForm("invalid form", "target");
		if (form == NULL) {
			std::cout << "Form creation failed as expected" << std::endl;
		}
	}

	std::cout << "\n========== TEST 3: Sign and execute forms ==========" << std::endl;
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		Form* form;

		form = intern.makeForm("shrubbery creation", "garden");
		if (form) {
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("robotomy request", "Robot");
		if (form) {
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		form = intern.makeForm("presidential pardon", "Prisoner");
		if (form) {
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	return 0;
}
