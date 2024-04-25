#include "../inc/Cat.hpp"

Cat::Cat() {
    if (VERBOSE)
        std::cout << "[Cat] default constructor called" << std::endl;
    this->_myBrain = new Brain();
    this->_type = "Cat";
}

Cat::Cat(const Cat & cp) : Animal(cp){
    if (VERBOSE)
        std::cout << "[Cat] default copy constructor called" << std::endl;
    *this = cp;
}

Cat::~Cat() {
    if (VERBOSE)
        std::cout << "[Cat] default destructor called" << std::endl;
    delete this->_myBrain;
}

Cat     &Cat::operator=(const Cat & cp) {
    if (VERBOSE)
        std::cout << "[Cat] copy overload operator called" << std::endl;
    this->_type = cp.getType();
    this->_myBrain = new Brain(*cp.getBrain());
    return (*this);
}

void    Cat::makeSound() const {
    std::cout << "Cat custom sound" << std::endl;
}

Brain   *Cat::getBrain() const {
    return this->_myBrain;
}