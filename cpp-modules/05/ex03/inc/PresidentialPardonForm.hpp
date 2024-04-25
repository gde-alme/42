#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	protected:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &);
		void	execute(Bureaucrat const &) const;
};

std::ostream	&operator<<(std::ostream &, const PresidentialPardonForm &);

#endif