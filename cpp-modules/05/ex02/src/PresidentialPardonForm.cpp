#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/macros.h"

/* constructors */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] protected constructor called" << std::endl;
	this->_target = "";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] default constructor called" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm(ref) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] copy constructor called" << std::endl;
	*this = ref;
}

/* destructors */
PresidentialPardonForm::~PresidentialPardonForm() {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] default destructor called" << std::endl;
}

/* operators */
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &ref) {
	if (VERBOSE)
		std::cout << "[PresidentialPardonForm] copy operator called" << std::endl;
	this->_target = ref._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const PresidentialPardonForm &me) {
	fd << "Form name -> " << me.getName() << std::endl << "Grade to sign -> " << me.getGradeSign() << std::endl;
	fd << "Grade to exec -> " << me.getGradeExec() << std::endl << "Is signed -> ";
	if (me.getSigned()) fd << "yes"; else fd << "nop";
	return (fd);
}
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	try { AForm::execute(executor); }
	catch (AForm::FormNotSignedException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	catch (AForm::GradeTooLowException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	std::cout << this->_target << " has been pardoned by the doubble headed Zaphod Beeblebrox" << std::endl;
}