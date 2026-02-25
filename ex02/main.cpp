#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"

int main() {
	std::cout << "===== TEST 1 (ShrubberyCreationForm)=====" << std::endl;

	try {
		Bureaucrat b1("CF", 145);
		Bureaucrat b2("Simon", 137);
		ShrubberyCreationForm f1("home");
		b1.signForm(f1);
		b2.executeForm(f1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== TEST 2 (ShrubberyCreationForm)=====" << std::endl;

	try {
		Bureaucrat b1("CF", 145);
		Bureaucrat b2("Simon", 145);
		ShrubberyCreationForm f1("home");
		b1.signForm(f1);
		b2.executeForm(f1);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}