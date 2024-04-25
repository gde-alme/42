#include "../inc/MateriaSource.hpp"
#include "../inc/macros.hpp"

MateriaSource::MateriaSource() {
	if (VERBOSE)
		std::cout << "[MateriaSource] default constructor called" << std::endl;
	for (int idx = 0; idx < 4; idx++) {
		this->_toClone[idx] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	if (VERBOSE)
		std::cout << "[MateriaSource] default destructor called" << std::endl;
	/*for (int idx = 0; idx < 4; idx++) {
		if (this->_toClone[idx] != NULL)
			delete this->_toClone[idx];
	}*///lol
}

MateriaSource::MateriaSource(const MateriaSource & ref) : IMateriaSource(ref) {
	if (VERBOSE)
		std::cout << "[MateriaSource] deafult copy constructor called" << std::endl;
	*this = ref;
}

MateriaSource &MateriaSource::operator=(const MateriaSource & ref) {
	if (VERBOSE)
		std::cout << "[MateriaSource] copy overload operator called" << std::endl;
	for (int idx = 0; idx < 4; idx++) {
		if (this->_toClone[idx] != NULL)
			delete this->_toClone[idx];
		this->_toClone[idx] = ref._toClone[idx];
	}
	return (*this);
}

/* Learns new AMateria if possible */
void	MateriaSource::learnMateria(AMateria *m) {
	for (int idx = 0; idx < 4; idx++) {
		if (this->_toClone[idx] == NULL) {
			this->_toClone[idx] = m;
			return ;
		}
	}
}

/* if any AMateria with same type and the one passed as parameter return said AMateria else NULL */
AMateria *MateriaSource::createMateria(std::string const & type) {
	for (int idx = 0; idx < 4; idx++) {
		if (this->_toClone[idx] != NULL && this->_toClone[idx]->getType().compare(type) == 0) {
			return (this->_toClone[idx]);
		}
	}
	return (NULL);
}