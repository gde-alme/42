#include "../inc/Base.hpp"
#include "../inc/macros.hpp"

Base::~Base() {
	if (VERBOSE)
		std::cout << "[Base] default destructor called" << std::endl;
}