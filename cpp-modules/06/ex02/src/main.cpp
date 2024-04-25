#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include <cstdlib>
#include <ctime>

Base	*generate() {
	srand(time(NULL)); //seed rand with c_time

	switch (rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void	identify(Base *ptr) {
	/* In C++, you can use dynamic_cast to identify the actual object pointed to by a base class pointer or reference,
		by casting it to a pointer or reference of a derived class and checking if it is NULL */
	if (dynamic_cast<A*>(ptr))
		std::cout << "It's an A !" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "It's a B !" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "It's a C !" << std::endl;
	else
		std::cout << "It's a monster!" << std::endl;
}

void	identify(Base &ptr) {
	try {
		A &a_ptr = dynamic_cast<A&>(ptr);
		std::cout << "It's an A !" << std::endl;
		return ((void)a_ptr);
	} catch (std::exception &e) {
		std::cout << "Not an A" << std::endl;
	}
	try {
		B &b_ptr = dynamic_cast<B&>(ptr);
		std::cout << "It's a B !" << std::endl;
		return ((void)b_ptr);
	} catch (std::exception &e) {
		std::cout << "Not a B" << std::endl;
	}
	try {
		C &c_ptr = dynamic_cast<C&>(ptr);
		std::cout << "It's a C !" << std::endl;
		return ((void)c_ptr);
	} catch (std::exception &e) {
		std::cout << "Not a C" << std::endl;
	}
}

int main() {
	Base	*base_ptr = generate();

	identify(base_ptr);

	identify(*base_ptr);

	delete base_ptr;
}