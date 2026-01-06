#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high! (Max is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low! (Min is 150)";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {

	if (grade < 1)
		throw GradeTooHighException();  
	if (grade > 150)
		throw GradeTooLowException();   

	this->_grade = grade;  
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {

		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {

	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {

	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
