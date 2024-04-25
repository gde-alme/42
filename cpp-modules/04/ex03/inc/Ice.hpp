#ifndef __ICE_HPP__
#define __ICE_HPP__

# include "../inc/AMateria.hpp"

class Ice : public AMateria {
	private:
		std::string _type;
	protected:
	public:
		Ice();
		Ice(const Ice & cp);
		~Ice();
		Ice & operator=(const Ice & cp);
		std::string const & getType() const;
		Ice *clone() const;
		void	use(ICharacter &target);
};

#endif