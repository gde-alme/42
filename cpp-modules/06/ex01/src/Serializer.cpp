#include "../inc/macros.hpp"
#include "../inc/Serializer.hpp"

Serialize::Serialize() {
	if (VERBOSE)
		std::cout << "[Serialize] default constructor called" << std::endl;
}

Serialize::Serialize(const Serialize &ref) {
	if (VERBOSE)
		std::cout << "[Serialize] copy constructor called" << std::endl;
	if (this != &ref)
		*this = ref;
}

Serialize	&Serialize::operator=(const Serialize &ref) {
	if (this != &ref)
		std::cout << "cp cp cp" << std::endl;
	return (*this);
}

Serialize::~Serialize() {
	if (VERBOSE)
		std::cout << "[Serialize] default destructor called" << std::endl;
}

uintptr_t	Serialize::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serialize::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}