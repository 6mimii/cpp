#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", 72, 45), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: Form(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSigned()) throw Form::NotSignedException();
	if (executor.getGrade() > getGradeToExecute()) throw Form::GradeTooLowException();

	std::cout << "* BZZZZZT! BZZZZZT! * (Drilling noises)" << std::endl;

	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
	}
}
