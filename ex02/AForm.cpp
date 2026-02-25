#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

AForm::AForm() : _name("noname"), _isSigned(false), _gradeToSign(50), _gradeToExecute(10) {}
AForm::~AForm() {}
AForm::AForm(const std::string& name, int gradeToSign, const int gradeToExecute)
		: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name),
		_isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	this->_isSigned = other._isSigned;
	return *this;
}

const std::string& AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

int AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! (AForm)";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! (AForm)";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Name: " << obj.getName() << ", " << "Signed or not: " << (obj.getIsSigned() ? "YES" : "NO") << ", "
	   << "Grade required to sign: " << obj.getGradeToSign() << ", "
	   << "Grade required to execute: " << obj.getGradeToExecute();
	return os;
}