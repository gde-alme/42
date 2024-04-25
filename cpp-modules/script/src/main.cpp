#include "../inc/cpp.hpp"

int main(int argc, char **argv, char **env) {
	Cpp	cpp;


	if (argc == 3) {
		if (std::string(argv[1]) == "-class")
			cpp.createClass(argv[2]);
	} else if (argc == 2) {
		if (std::string(argv[1]) == "-init")
			cpp.initEnv();
	}
	else
		std::cout << "\nUsage:\n\tcpp -option [params]\n" << std::endl;
}
