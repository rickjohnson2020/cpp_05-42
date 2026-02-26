#include "./Intern.hpp"

Intern::Intern() {}
Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

// const char* Intern::FormNotFoundException::what() const throw() {
// 	return "Form not found!";
// }

AForm* Intern::createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	struct Entry {
		const char* name;
		AForm* (*create)(const std::string&);
	};

	static const Entry table[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};

	for (size_t i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
		if (formName == table[i].name) {
			AForm* f = table[i].create(target);
			std::cout << "Intern creates " << f->getName() << std::endl;
			return f;
		}
	}
	std::cout << "Intern couldn't find form: " << formName << std::endl;
	// throw Intern::FormNotFoundException();
	return NULL;

}