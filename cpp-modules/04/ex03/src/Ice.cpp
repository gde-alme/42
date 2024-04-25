#include "../inc/Ice.hpp"
#include "../inc/macros.hpp"

Ice::Ice() : AMateria("ice") {
	if (VERBOSE)
		std::cout << "[Ice] default constructor called" << std::endl;
}

Ice::Ice(const Ice & cp) : AMateria("ice") {
	if (VERBOSE)
		std::cout << "[Ice] default copy constructor called" << std::endl;
	*this = cp;
}

Ice::~Ice() {
	if (VERBOSE)
		std::cout << "[Ice] default destructor called" << std::endl;
}

Ice & Ice::operator=(const Ice & cp) {
	if (VERBOSE)
		std::cout << "[Ice] copy overload operator called" << std::endl;
	this->_type = cp._type;
	return (*this);
}

std::string const & Ice::getType() const {
	return (this->_type);
}

Ice	*Ice::clone() const {
	Ice	*cp = new Ice(*this);
	return (cp);
}

void	Ice::use(ICharacter &target) {
	std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}