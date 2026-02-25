#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", 25, 5), _target("notarget") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
		: AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	_target = other._target;
	return *this;
}