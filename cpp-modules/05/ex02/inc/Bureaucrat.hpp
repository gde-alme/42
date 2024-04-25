#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		Bureaucrat();
	public:
		/* constructors */
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &);
		/* destructors */
		~Bureaucrat();
		/* operators */
		Bureaucrat &operator=(const Bureaucrat &);
		/* utils */
		std::string	getName() const;
		int			getGrade() const;
		/* actions */
		void		incrementGrade();
		void		decrementGrade();
		void 		signAForm(AForm &);
		void		executeForm(AForm const &);
		/* exceptions */
		class	GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Max grade is 1");
				}
		} toHigh;
		class	GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Min grade is 150");
				}
		} toLow;
};

std::ostream	&operator<<(std::ostream &, const Bureaucrat &);

#endif