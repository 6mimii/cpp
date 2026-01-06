#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: Form("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: Form(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		Form::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!getSigned()) throw Form::NotSignedException();
	if (executor.getGrade() > getGradeToExecute()) throw Form::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
