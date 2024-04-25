#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	protected:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &);
		void	execute(Bureaucrat const &) const;
};

std::ostream	&operator<<(std::ostream &, const RobotomyRequestForm &);

#endif