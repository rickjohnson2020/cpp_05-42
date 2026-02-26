#include "./Bureaucrat.hpp"
#include "./Intern.hpp"
#include <ctime>

int main() {
	std::cout << "===== TEST 1 =====" << std::endl;

	Intern someRandomIntern;
	AForm* f1;
	f1 = someRandomIntern.makeForm("random form", "random target");
	if (f1 != NULL) {
		try {
			Bureaucrat b1("CF", 1);
			b1.signForm(*f1);
			b1.executeForm(*f1);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete f1;
	}

	std::cout << "\n===== TEST 2 =====" << std::endl;

	AForm* f2;
	f2 = someRandomIntern.makeForm("robotomy request", "Bender");

	if (f2 != NULL) {
		try {
			Bureaucrat b1("CF", 1);
			b1.signForm(*f2);
			b1.executeForm(*f2);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete f2;
	}

	std::cout << "\n===== TEST 3 =====" << std::endl;

	AForm* f3;
	f3 = someRandomIntern.makeForm("shrubbery creation", "home");

	if (f3 != NULL) {
		try {
			Bureaucrat b1("CF", 1);
			b1.signForm(*f3);
			b1.executeForm(*f3);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete f3;
	}

	std::cout << "\n===== TEST 4 =====" << std::endl;

	AForm* f4;
	f4 = someRandomIntern.makeForm("presidential pardon", "Simon");

	if (f4 != NULL) {
		try {
			Bureaucrat b1("CF", 20);
			b1.signForm(*f4);
			b1.executeForm(*f4);
		} catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		delete f4;
	}

	return 0;
}