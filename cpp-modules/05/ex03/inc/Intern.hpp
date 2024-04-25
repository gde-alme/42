#ifndef __INTERN_HPP__
#define __INTERN_HPP__

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern {
	public:
		Intern();
		Intern(const Intern &);
		~Intern();
		Intern	&operator=(const Intern &);
		AForm *makeForm(std::string name, std::string target);
};

#endif
