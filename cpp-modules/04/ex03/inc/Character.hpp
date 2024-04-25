#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

# include "ICharacter.hpp"
# include <string>
# include <iostream>

class Character : public ICharacter {
    private:
		AMateria	*_inventory[4];
		std::string _name;
    protected:
    public:
		Character();
		Character(const std::string name);
		~Character();
		Character(const Character &ref);
		Character	&operator=(const Character &ref);
		std::string const &getName() const;
		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter &target);
};

#endif