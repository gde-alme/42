#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource {
	private:
		AMateria *_toClone[4];
	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource & ref);
		MateriaSource &operator=(const MateriaSource & ref);
		void	learnMateria(AMateria *m);
		AMateria	*createMateria(std::string const & type);
};

#endif