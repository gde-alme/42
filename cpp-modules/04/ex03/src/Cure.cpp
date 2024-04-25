#include "../inc/Cure.hpp"
#include "../inc/macros.hpp"

Cure::Cure() : AMateria("cure") {
    if (VERBOSE)
        std::cout << "[Cure] default constructor called" << std::endl;
}

Cure::Cure(const Cure & cp) : AMateria("cure") {
    if (VERBOSE)
        std::cout << "[Cure] default copy constructor called" << std::endl;
    *this = cp;
}

Cure & Cure::operator=(const Cure & cp) {
    if (VERBOSE)
        std::cout << "[Cure] copy overload operator called" << std::endl;
    this->_type = cp._type;
	return (*this);
}

Cure::~Cure() {
    if (VERBOSE)
        std::cout << "[Cure] default destructor called" << std::endl;
}

std::string const & Cure::getType() const {
    return (this->_type);
}

Cure    *Cure::clone() const {
    Cure    *cp = new Cure;
    return (cp);
}

void    Cure::use(ICharacter &target) {
    std::cout << "heals " << target.getName() << "'s wounds" << std::endl;
}