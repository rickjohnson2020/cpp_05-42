#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noname"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
};

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	this->_grade = other._grade;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return this->_name;
}

int Bureaucrat::getGrade() const {
	return this->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! (Bureaucrat)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! (Bureaucrat)";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", " << "bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << this->_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
	try {
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	} catch (const std::exception& e) {
		std::cout << this->_name << " failed to execute " << form.getName() << ": ";
		std::cout << e.what() << std::endl;
	}
}