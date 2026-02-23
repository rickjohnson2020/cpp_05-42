#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150) {}

Bureaucrat::Bureaucrat(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = grade;
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->_grade = other._grade;
	return *this;
}

const std::string Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooHighException();
	this->_grade++;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooLowException();
	this->_grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too hign!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}