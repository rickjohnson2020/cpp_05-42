#include "./AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;

public:
	RobotomyRequestForm();
	~RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void execute(const Bureaucrat& executor) const;
};