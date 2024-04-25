#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main() {
	Intern		slave;

	AForm *form1 = slave.makeForm("ShrubberyCreation", "form1");

	std::cout << *form1 << std::endl;

	delete form1;

	return (0);
}
