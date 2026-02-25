#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main() {
	std::cout << "===== TEST 1 =====" << std::endl;

	try {
		Bureaucrat b("Simon", 100);
		Form f("Form A", 151, 100);

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);

		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Failed to create an object: ";
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== TEST 2 =====" << std::endl; 

	try {
		Bureaucrat b("Simon", 100);
		Form f("Form A", 100, 50);

		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);

		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception thrown: ";
		std::cout << e.what() << std::endl;
	}

	std::cout << "===== TEST 3 =====" << std::endl;

	try {
		Bureaucrat b("Simon", 100);
		Form f("Form B", 50, 10);
		
		std::cout << b << std::endl;
		std::cout << f << std::endl;

		b.signForm(f);

		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Exception thrown: ";
		std::cout << e.what() << std::endl;
	}

	return 0;
}