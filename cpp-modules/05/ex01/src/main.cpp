#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

//exec with argv "talk" to test << operator
int main() {
	//Bureaucrat Ford; //throw exception error
	try {
		Bureaucrat Ford("Ford", 152);
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << std::endl; }
	catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << std::endl; }

	Form simpleForm("muito dificil", 42, 1);	

	std::cout << simpleForm << std::endl;

	Bureaucrat Ford("Ford", 21);

	Ford.signForm(simpleForm);
	return (0);
}