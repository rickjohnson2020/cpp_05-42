#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", 145, 137), _target("notarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
		: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}

//TODO
void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	//TODO: better to put this in try-catch?
	createFile(_target);
}

void createFile(std::string target) {
	const std::string tree = "          &&& &&  & &&\n      && &\\/&\\|& ()|/ @, &&\n      &\\/(/&/&||/& /_/)_&/_&\n   &() &\\/&|()|/&\\/ '%\" & ()\n  &_\\_&&_\\ |& |&&/&__%_/_& &&\n&&   && & &| &| /& & % ()& /&&\n ()&_---()&\\&\\|&&-&&--%---()~\n     &&     \\|||\n             |||\n             |||\n             |||\n       , -=-~  .-^- _\n";
	// std::string fileName = target + "_shrubbery";
	std::ofstream outfile((target + "_shrubbery").c_str());

	outfile << tree << std::endl;

	outfile.close();
}