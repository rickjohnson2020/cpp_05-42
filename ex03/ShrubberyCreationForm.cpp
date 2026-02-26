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

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	AForm::checkExecutable(executor);
	createFile();
	std::cout << _target << "_shrubbery file created" << std::endl;
}

void ShrubberyCreationForm::createFile() const {
	const std::string tree =
			"          &&& &&  & &&\n"
			"      && &\\/&\\|& ()|/ @, &&\n"
			"      &\\/(/&/&||/& /_/)_&/_&\n"
			"   &() &\\/&|()|/&\\/ '%\" & ()\n"
			"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
			"&&   && & &| &| /& & % ()& /&&\n"
			" ()&_---()&\\&\\|&&-&&--%---()~\n"
			"     &&     \\|||\n"
			"             |||\n"
			"             |||\n"
			"             |||\n"
			"       , -=-~  .-^- _\n";

	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
		throw std::runtime_error("File open failed");

	outfile << tree;
}