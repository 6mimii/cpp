#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>

int main()
{

	std::srand(std::time(0));

	Bureaucrat boss("Big Boss", 1);
	Bureaucrat intern("Poor Intern", 150);

	ShrubberyCreationForm shrub("Garden");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Criminal");

	std::cout << "\n--- TEST 1: Intern tries to sign/execute ---" << std::endl;
	intern.signForm(shrub);
	intern.executeForm(shrub);  

	std::cout << "\n--- TEST 2: Boss signs everything ---" << std::endl;
	boss.signForm(shrub);
	boss.signForm(robo);
	boss.signForm(pardon);

	std::cout << "\n--- TEST 3: Boss executes Shrubbery ---" << std::endl;
	boss.executeForm(shrub); 

	std::cout << "\n--- TEST 4: Boss executes Robotomy ---" << std::endl;
	boss.executeForm(robo);
	boss.executeForm(robo);
	boss.executeForm(robo); 

	std::cout << "\n--- TEST 5: Boss executes Pardon ---" << std::endl;
	boss.executeForm(pardon);

	std::cout << "\n--- TEST 6: Intern tries to execute signed forms ---" << std::endl;

	intern.executeForm(robo);
	intern.executeForm(pardon);

	return 0;
}
