#ifndef AFORM_H
#define AFORM_H

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

public:
	AForm();
	virtual ~AForm();
	AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);

	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);

	virtual void execute(const Bureaucrat& executor) const = 0;
	void checkExecutable(const Bureaucrat& executor) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif