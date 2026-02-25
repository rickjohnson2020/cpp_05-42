#include "./Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("noname"), _isSigned(false), _gradeToSign(50), _gradeToExecute(10) {}
Form::~Form() {}
Form::Form(const std::string& name, int gradeToSign, const int gradeToExecute)
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

const std::string& Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

int Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high! (Form)";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low! (Form)";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Name: " << obj.getName() << ", " << "Signed or not: " << obj.getIsSigned() << ", "
	   << "Grade required to sign: " << obj.getGradeToSign() << ", "
	   << "Grade required to execute: " << obj.getGradeToExecute();
	return os;
}