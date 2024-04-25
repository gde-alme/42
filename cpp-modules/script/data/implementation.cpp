#include "INC/CLASSNAME.hpp"

CLASSNAME::CLASSNAME() {
	if (VERBOSE)
		std::cout << "[CLASSNAME] default constructor called" << std::endl;
}

CLASSNAME::CLASSNAME(const CLASSNAME &ref) {
	if (VERBOSE)
		std::cout << "[CLASSNAME] default constructor called" << std::endl;
	*this = ref;
}

CLASSNAME	&CLASSNAME::operator=(const CLASSNAME &ref) {
	return (*this);
}

CLASSNAME::~CLASSNAME() {
	if (VERBOSE)
		std::cout << "[CLASSNAME] default constructor called" << std::endl;
}
