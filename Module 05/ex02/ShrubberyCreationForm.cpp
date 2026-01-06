#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: Form("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: Form("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: Form(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	if (!getSigned()) {
		throw Form::NotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw Form::GradeTooLowException();
	}

	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open()) {
		std::cerr << "Error: Could not create file." << std::endl;
		return;
	}

	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;

	outfile.close();
}
