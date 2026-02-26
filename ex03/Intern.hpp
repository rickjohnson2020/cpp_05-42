#ifndef INTERN_HPP
#define INTERN_HPP

#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);

	AForm* makeForm(const std::string& formName, const std::string& target);

	// class FormNotFoundException : public std::exception {
	// public:
	// 	virtual const char* what() const throw();
	// };

private:
	static AForm* createShrubbery(const std::string& target);
	static AForm* createRobotomy(const std::string& target);
	static AForm* createPresidential(const std::string& target);
};

#endif