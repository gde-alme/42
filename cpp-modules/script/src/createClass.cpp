#include "../inc/cpp.hpp"

std::string	Cpp::_parseLine(std::string line, std::string class_name) {
	std::string	caps_name = class_name;
	for (std::string::iterator it = class_name.begin(), it2 = caps_name.begin(); it != class_name.end(); it++, it2++) {
		*it2 = std::toupper(*it);
	}
	std::string	csub 	= "CLASSNAME";
	size_t 		pos;

	int	i = 0;
	while ((pos = line.find(csub)) != std::string::npos) {
		if ((line.find("__CLASSNAME_HPP__")) != std::string::npos) {
			line.replace(pos, csub.length(), caps_name);
			return (line);
		} else if ((line.find("CLASSNAME.hpp")) != std::string::npos) {
			line.replace(pos, csub.length(), caps_name);
			return (line);
		} else {
			line.replace(pos, csub.length(), class_name);
			i++;
		}
	}
	return (line);
}
void	Cpp::createClass(std::string class_name) {
	class_name[0] = std::toupper(class_name[0]); //parse class name
	std::string		curr_line;

	std::ofstream	fd_decla(class_name + ".hpp");
	std::ifstream	fd_decla_ex(std::string(LOCALPATH) + ".cpp/data/declaration.hpp");
	if (fd_decla.is_open()) {
		if (fd_decla_ex.is_open()) {
			while (std::getline(fd_decla_ex, curr_line)) {
				fd_decla << _parseLine(curr_line, class_name) << std::endl;
			}
			fd_decla_ex.close();
		}
		fd_decla.close();
	}

	std::ofstream	fd_imple(class_name + ".cpp");
	std::ifstream	fd_imple_ex(std::string(LOCALPATH) + ".cpp/data/implementation.cpp");
	if (fd_imple.is_open()) {
		if (fd_imple_ex.is_open()) {
			while (std::getline(fd_imple_ex, curr_line)) {
				fd_imple << _parseLine(curr_line, class_name) << std::endl;
			}
			fd_imple_ex.close();
		}
		fd_imple.close();
	}
}
