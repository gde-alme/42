#include "../inc/Form.hpp"
#include "../inc/macros.h"

/* constructors */
Form::Form() : _name(""), _gradeSign(0), _gradeExec(0) {
	if (VERBOSE)
		std::cout << "[Form] private constructor called" << std::endl;
	this->_signed = false;
}

Form::Form(const Form &ref) : _name(ref.getName()), _gradeSign(ref.getGradeSign()), _gradeExec(ref.getGradeExec()) {
	if (VERBOSE)
		std::cout << "[Form] copy constructor called" << std::endl;
	*this = ref;
}

Form::Form(const std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (VERBOSE)
		std::cout << "[Form] default constructor called" << std::endl;
	if (gradeSign < 1) throw tooHigh; else if (gradeSign > 150) throw tooLow;
	if (gradeExec < 1) throw tooHigh; else if (gradeExec > 150) throw tooLow;
	this->_signed = false;
}

/* destructors */
Form::~Form() {
	if (VERBOSE)
		std::cout << "[Form] default destructor called" << std::endl;
}

/* operators overload */
Form	&Form::operator=(const Form &ref) {
	if (VERBOSE)
		std::cout << "[Form] default copy overload operator called" << std::endl;
	this->_signed = ref.getSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const Form &me) {
	fd << "Form name-> " << me.getName() << std::endl;
	fd << "Form is signed -> "; if (me.getSigned()) { fd << "Yes" << std::endl; } else { fd << "Nop" << std::endl; };
	fd << "Form gradeSign -> " << me.getGradeSign() << std::endl;
	fd << "Form gradeExec -> " << me.getGradeExec();
	return (fd);
}

/* utils */
std::string	Form::getName() const {
	return (this->_name);
}

bool	Form::getSigned() const {
	return (this->_signed);
}

int		Form::getGradeSign() const {
	return (this->_gradeSign);
}

int		Form::getGradeExec() const {
	return (this->_gradeExec);
}

void		Form::beSigned(const Bureaucrat &dude) {
	if (dude.getGrade() > this->getGradeSign())
		throw tooLow;
	this->_signed = true;
}