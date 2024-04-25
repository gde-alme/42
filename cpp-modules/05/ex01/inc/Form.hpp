#ifndef __FORM_HPP__
#define __FORM_HPP__

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
		Form();
	public:
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &ref);
		~Form();
		Form	&operator=(const Form &ref);
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(const Bureaucrat &dude);
		class GradeTooHighException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Max grade is 1");
				}
		} tooHigh;
		class GradeTooLowException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Min grade is 150");
				}
		} tooLow;
};

std::ostream	&operator<<(std::ostream &fd, const Form &me);

#endif