#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- TEST 1: Creating Forms ---" << std::endl;
	try {
		Form contract("Contract A1", 50, 100);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error creating form: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2: Signing Success ---" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		Form taxForm("Tax Form", 10, 10);

		std::cout << "Before: " << taxForm << std::endl;
		boss.signForm(taxForm);
		std::cout << "After:  " << taxForm << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 3: Signing Failure (Grade too low) ---" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		Form secretDoc("Top Secret", 1, 1);

		std::cout << "Before: " << secretDoc << std::endl;
		intern.signForm(secretDoc);  
		std::cout << "After:  " << secretDoc << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4: Form creation Error ---" << std::endl;
	try {
		Form invalid("Impossible", 0, 100);
	}
	catch (std::exception &e) {
		std::cout << "Caught expected error: " << e.what() << std::endl;
	}

	return 0;
}
