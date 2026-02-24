#include "./Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Simon", 0);
	} catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "Failed to create an object: " << e.what() << std::endl;
	}

	Bureaucrat b("Simon", 150);

	std::cout << b << std::endl;
	try {
		b.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "Failed to decrement grade: " << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	try {
		for (int i = 0; i < 200; i++) {
			b.incrementGrade();
		}
	} catch (const std::exception& e) {
		std::cout << "Failed to increment grade: " << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	return 0;

}