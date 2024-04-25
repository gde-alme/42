#include "../inc/AForm.hpp"
#include "../inc/macros.h"

/* constructors */
AForm::AForm() : _name(""), _gradeSign(0), _gradeExec(0) {
	if (VERBOSE)
		std::cout << "[AForm] private constructor called" << std::endl;
	this->_signed = false;
}

AForm::AForm(const AForm &ref) : _name(ref.getName()), _gradeSign(ref.getGradeSign()), _gradeExec(ref.getGradeExec()) {
	if (VERBOSE)
		std::cout << "[AForm] copy constructor called" << std::endl;
	*this = ref;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (VERBOSE)
		std::cout << "[AForm] default constructor called" << std::endl;
	if (gradeSign < 1) throw tooHigh; else if (gradeSign > 150) throw tooLow;
	if (gradeExec < 1) throw tooHigh; else if (gradeExec > 150) throw tooLow;
	this->_signed = false;
}

/* destructors */
AForm::~AForm() {
	if (VERBOSE)
		std::cout << "[AForm] default destructor called" << std::endl;
}

/* operators overload */
AForm	&AForm::operator=(const AForm &ref) {
	if (VERBOSE)
		std::cout << "[AForm] default copy overload operator called" << std::endl;
	this->_signed = ref.getSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &fd, const AForm &me) {
	fd << "AForm name-> " << me.getName() << std::endl;
	fd << "AForm is signed -> "; if (me.getSigned()) { fd << "Yes" << std::endl; } else { fd << "Nop" << std::endl; };
	fd << "AForm gradeSign -> " << me.getGradeSign() << std::endl;
	fd << "AForm gradeExec -> " << me.getGradeExec();
	return (fd);
}

/* utils */
std::string	AForm::getName() const {
	return (this->_name);
}

bool	AForm::getSigned() const {
	return (this->_signed);
}

int		AForm::getGradeSign() const {
	return (this->_gradeSign);
}

int		AForm::getGradeExec() const {
	return (this->_gradeExec);
}

void		AForm::beSigned(const Bureaucrat &dude) {
	if (dude.getGrade() > this->getGradeSign())
		throw tooLow;
	this->_signed = true;
	std::cout << this->getName() << " just got signed by " << dude.getName() << std::endl;
}

void		AForm::execute(Bureaucrat const &executor) const {
	if (!(this->getSigned()))
		throw notSigned;
	if (executor.getGrade() > this->getGradeExec())
		throw tooLow;
}