#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/macros.h"

/* constructors */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] protected constructor called" << std::endl;
	this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] useful constructor called" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] copy constructor called" << std::endl;
	*this = ref;
}

/* destructors */
ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] default destructor called" << std::endl;
}

/* operators */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref) {
	if (VERBOSE)
		std::cout << "[ShrubberyCreationForm] copy operator called" << std::endl;
	this->_target = ref._target;
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const ShrubberyCreationForm &me) {
	fd << "Form name -> " << me.getName() << std::endl << "Grade to sign -> " << me.getGradeSign() << std::endl;
	fd << "Grade to exec -> " << me.getGradeExec() << std::endl << "Is signed -> ";
	if (me.getSigned()) fd << "yes"; else fd << "nop";
	return (fd);
}

/* actions */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	try { AForm::execute(executor); }
	catch (AForm::FormNotSignedException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	catch (AForm::GradeTooLowException &e) { std::cout << "Can't execute bc " << e.what() << std::endl; return ;}
	std::string fd_name(this->_target + "_shrubbery");
	std::ofstream	fd(&fd_name[0]);
	fd << "           \\/ |    |/" << std::endl;
	fd << "        \\/ / \\||/  /_/___/_" << std::endl;
	fd << "         \\/   |/ \\/" << std::endl;
	fd << "    _\\__\\_\\   |  /_____/_" << std::endl;
	fd << "           \\  | /          /" << std::endl;
	fd << "  __ _-----`  |{,-----------~" << std::endl;
	fd << "            \\ }{" << std::endl;
	fd << "             }{{" << std::endl;
	fd << "             }}{" << std::endl;
	fd << "             {{}" << std::endl;
	fd << "       , -=-~{ .-^- _" << std::endl;
	fd << "  ejm        `}" << std::endl;
	fd << "              {" << std::endl;
	fd.close();
}