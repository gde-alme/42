#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/macros.h"

/* constructors */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] protected constructor called" << std::endl;
	this->_target = "";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] target constructor called" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm(ref) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] copy constructor called" << std::endl;
	*this = ref;
}

/* destructors */
RobotomyRequestForm::~RobotomyRequestForm() {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] default destructor called" << std::endl;
}

/* operators */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref) {
	if (VERBOSE)
		std::cout << "[RobotomyRequestForm] copy operator called" << std::endl;
	this->_target = ref._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const RobotomyRequestForm &me) {
	fd << "Form name -> " << me.getName() << std::endl << "Grade to sign -> " << me.getGradeSign() << std::endl;
	fd << "Grade to exec -> " << me.getGradeExec() << std::endl << "Is signed -> ";
	if (me.getSigned()) fd << "yes"; else fd << "nop";
	return (fd);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	try { AForm::execute(executor); }
	catch (AForm::FormNotSignedException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	catch (AForm::GradeTooLowException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	std::cout << "uk drill" << std::endl;
	std::cout << "fr drill" << std::endl;
	std::time_t t = std::time(0);
	std::tm	*now = std::localtime(&t);
	bool random = (rand() % 100 * (now->tm_sec + 1) % 2) != 0;
	if (random == true)
		std::cout << this->_target << " has been rebotomized" << std::endl;
	else
		std::cout << this->_target << " robotomy attempt failed" << std::endl;
}