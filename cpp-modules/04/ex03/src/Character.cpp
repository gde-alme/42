#include "../inc/Character.hpp"
#include "../inc/macros.hpp"

Character::Character() {
	if (VERBOSE)
		std::cout << "[Character] default constructor called" << std::endl;
	this->_name = "Somebody";
	for (int idx = 0; idx < 4; idx++) {
		this->_inventory[idx] = NULL;
	}
}

Character::Character(const std::string name) : _name(name){
	if (VERBOSE)
		std::cout << "[Character] name constructor called" << std::endl;
	for (int idx = 0; idx < 4; idx++) {
		this->_inventory[idx] = NULL;
	}
}

Character::~Character() {
	if (VERBOSE)
		std::cout << "[Character] default destructor called" << std::endl;
	for (int idx = 0; idx < 4; idx++) {
		if (this->_inventory[idx] != NULL)
			delete this->_inventory[idx];
	}
}

Character::Character(const Character &ref) : ICharacter(ref) {
	if (VERBOSE)
		std::cout << "[Character] default copy constructor called" << std::endl;
	*this = ref;
}

Character	&Character::operator=(const Character &ref) {
	if (VERBOSE)
		std::cout << "[Character] copy operator overload called" << std::endl;
	this->_name = ref.getName();
	for (int idx = 0; idx < 4; idx++) {
		if (this->_inventory[idx] != NULL)
			delete this->_inventory[idx];
		this->_inventory[idx] = ref._inventory[idx];
	}
	return (*this);
}

std::string	const & Character::getName() const {
	return (this->_name);
}

void	Character::equip(AMateria *m) {
	for (int idx = 0; idx < 4; idx++) {
		if (this->_inventory[idx] == NULL) {
			this->_inventory[idx] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (this->_inventory[idx] != NULL) {
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
}