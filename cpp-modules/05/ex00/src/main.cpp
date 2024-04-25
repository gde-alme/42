#include "../inc/Bureaucrat.hpp"

//exec with argv "talk" to test << operator
int main(int argc, char **argv) {
	//Bureaucrat Ford; //throw exception error
	try {
		Bureaucrat Ford("Ford", 152);
	
		Ford.incrementGrade();

		std::cout << Ford << std::endl;

		for (int icr = 0; icr < 150; icr++) {
			if (argc > 1)
				if (std::string(argv[1]) == "talk")
					std::cout << Ford << std::endl;
			Ford.decrementGrade();
		}
	}
	catch (Bureaucrat::GradeTooHighException &e) { std::cout << e.what() << std::endl; return (0); }
	catch (Bureaucrat::GradeTooLowException &e) { std::cout << e.what() << std::endl; return (0); }

	return (0);
}