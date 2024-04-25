#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main() {
	Bureaucrat				bure("manel", 42);
	Bureaucrat				bure2("lenam", 148);

	/* ShrubberyCreationForm */
	std::cout << std::endl << "#======================================================#" << std::endl << std::endl;;
	std::cout << "ShrubberyCreationForm" << std::endl;

	ShrubberyCreationForm	form("hiWorld");

	std::cout << form << std::endl;

	try { form.beSigned(bure); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}

	form.execute(bure);

	std::cout << std::endl << "wont exec" << std::endl << std::endl;

	try { form.beSigned(bure2); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}

	form.execute(bure2);

	/* RobotomyRequestForm */
	std::cout << std::endl << "#======================================================#" << std::endl << std::endl;;
	std::cout << "RobotomyRequestForm" << std::endl;

	RobotomyRequestForm		form2("Marvin");
	
	Bureaucrat				bure_b("manel", 42);
	Bureaucrat				bure_b2("lenam", 148);

	std::cout << form2 << std::endl;

	try { form2.beSigned(bure_b); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}

	form2.execute(bure_b);

	std::cout << std::endl << "wont exec" << std::endl << std::endl;
	
	try { form2.beSigned(bure_b2); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}

	form2.execute(bure_b2);
	
	/* RobotomyRequestForm */
	std::cout << std::endl << "#======================================================#" << std::endl << std::endl;;
	std::cout << "PresidentialPardonForm" << std::endl;

	PresidentialPardonForm	form3("LuckyDoubbleHeadedFvcker");

	Bureaucrat bure_c("eque", 1);

	std::cout << form3 << std::endl;

	try { form3.beSigned(bure); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}

	std::cout << std::endl << "wont exec" << std::endl << std::endl;

	form3.execute(bure);

	std::cout << std::endl << "#======================================================#" << std::endl << std::endl;;

	try { form3.beSigned(bure_c); }
	catch (AForm::GradeTooLowException &e) { 
		std::cout << "Can't sign this form bc " << e.what() << std::endl;
	}
	
	bure_c.executeForm(form3);

	return (0);
}