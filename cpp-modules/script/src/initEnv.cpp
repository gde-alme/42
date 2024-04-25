#include "../inc/cpp.hpp"

void	Cpp::initEnv() {
	std::ofstream	makef("Makefile");
	std::ifstream	makef_ex(std::string(LOCALPATH) + ".cpp/data/Makefile");
	std::string	curr_line;

	if (makef.is_open()) {
		if (makef_ex.is_open()) {
			while (std::getline(makef_ex, curr_line)) {
				makef << curr_line << std::endl;
			}
			makef_ex.close();
		}
		makef.close();
	}
	mkdir("src", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
	mkdir("inc", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
}
