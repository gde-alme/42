#include "../inc/ScalarConverter.hpp"

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Usage: ./convert var_cpp_literal" << std::endl;
		return (0);
	}
	ScalarConverter a(argv[1]);
	try {
		a.convert();
	} catch (std::exception &e) { 
		std::cout << "\nCan't convert bc " << e.what() << std::endl << std::endl;
		return (0);
	}
	std::cout << std::endl << a << std::endl;
}