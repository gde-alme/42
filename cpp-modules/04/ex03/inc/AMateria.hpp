#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

# include <string>
# include <iostream>

# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	private:
		std::string _type;
	protected:
		AMateria();
	public:
		AMateria(std::string const & type);
		AMateria(const AMateria & cp);
		virtual ~AMateria();
		AMateria &operator=(const AMateria & cp);
		std::string const & getType() const;
		/*
						# Virtual class =0 #
			The idea is that a class can expose a certain function 
			while its subclasses have to implement it (no default behaviour)
		*/
		virtual AMateria * clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		
};

#endif