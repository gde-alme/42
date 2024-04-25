#ifndef __ICHARACTER_HPP__
#define __ICHARACTER_HPP__

# include "AMateria.hpp"

class AMateria;

class ICharacter {
	protected:
		const std::string _name;
	public:
	/* declaring virtual destructor here */
	virtual ~ICharacter() {};
	/* virtual funcs defenitions with =0 dont need to be implemented in interface */
	virtual std::string const & getName() const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter & target) = 0;
};

#endif