#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "./AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form);
	void executeForm(const AForm& form) const;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif