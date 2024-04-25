#ifndef __ShrubberyCREATIONFORM_HPP__
#define __ShrubberyCREATIONFORM_HPP__

# include "AForm.hpp"
# include <fstream>


class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	protected:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &);
		void	execute(Bureaucrat const &) const;
};

std::ostream &operator<<(std::ostream &, const ShrubberyCreationForm &);

#endif