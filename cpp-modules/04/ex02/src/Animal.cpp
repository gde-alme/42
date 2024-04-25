#include "../inc/Animal.hpp"

Animal::Animal() {
    if (VERBOSE)
        std::cout << "[Animal] default constructor called" << std::endl; 
}

Animal::Animal(const Animal & cp) {
    if (VERBOSE)
        std::cout << "[Animal] default copy constructor called" << std::endl;
    *this = cp;
}

Animal  & Animal::operator=(const Animal & cp) {
    this->_type = cp._type;
    return (*this);
}

Animal::~Animal() {
    if (VERBOSE)
        std::cout << "[Animal] default destructor called" << std::endl; 
}

std::string Animal::getType() const {
    return (this->_type);
}

void    Animal::makeSound() const {
    std::cout << "Random animal sound" << std::endl;
}