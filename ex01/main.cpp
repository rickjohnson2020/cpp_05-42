#include "./Bureaucrat.hpp"
#include "./Form.hpp"
#include <exception>

int main() {
	try {
		Bureaucrat b("Simon", 100);
		Form f("Form A", 100, 50);
		std::cout << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}