#ifndef __AForm_HPP__
#define __AForm_HPP__

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
		AForm();
	public:
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &ref);
		virtual ~AForm();
		AForm	&operator=(const AForm &ref);
		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(const Bureaucrat &);
		void		execute(Bureaucrat const &executor) const;
		class GradeTooHighException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("grade too high");
				}
		} tooHigh;
		class GradeTooLowException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("grade to low");
				}
		} tooLow;
		class FormNotSignedException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("this Form is not signed");
				}
		} notSigned;
};

std::ostream	&operator<<(std::ostream &fd, const AForm &me);

#endif