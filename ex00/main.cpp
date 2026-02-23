#include "./Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a(0);
	} catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << std::endl;
	}

}