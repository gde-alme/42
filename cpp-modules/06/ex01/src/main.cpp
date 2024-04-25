#include "../inc/Serializer.hpp"

void	smert(void *somePtr) {
	Data	*getPtr = reinterpret_cast<Data*>((uintptr_t)somePtr);

	std::cout << getPtr->someString << std::endl;
}

int main() {
	Data	*data_ptr = new Data;

	data_ptr->someString = "Hey, I'm a string!";
	data_ptr->someIntValue = 42;
	data_ptr->SomeFloatValue = 3.14159265f;

	Serialize	ptrMagic;

	void	*void_ptr = (void*)ptrMagic.serialize(data_ptr);

	smert(void_ptr);
}