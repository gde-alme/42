#include "../inc/Intern.hpp"
#include "../inc/macros.h"

Intern::Intern() {
	if (VERBOSE)
		std::cout << "[Intern] A wild intern appears" << std::endl;
}

Intern::Intern(const Intern &ref) {
	if (VERBOSE)
		std::cout << "[Intern] A copy of a wild intern appears" << std::endl;
	*this = ref;
}

Intern::~Intern() {
	if (VERBOSE)
		std::cout << "[Intern] The intern got promoted" << std::endl;
}

Intern	&Intern::operator=(const Intern &ref) {
	if (this != &ref) {/*-Werror*/}
	return (*this);
}

AForm	*newShrubberyForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*newRobotomyForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*newPresidentialForm(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	//function pointers or switch since no if/else chain is allowed
	std::string forms[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	AForm	*(*funcsPtr[3])(std::string) = {&newShrubberyForm, &newRobotomyForm, &newPresidentialForm};

	for (int i = 0; i < 3; i++) {
		if (name == forms[i]) {
			std::cout << "Intern creates " << forms[i] << std::endl;
			return (funcsPtr[i](target));
		}
	}
	std::cout << "Intern got lost with translation" << std::endl;
	return (NULL);
}