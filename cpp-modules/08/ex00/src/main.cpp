#include "../inc/easyfind.hpp"

int main() {
	int			values[] = {1, 5, 9, 3, 6, 2};
	std::vector<int>	v(values, values + sizeof(values) / sizeof(int));
	int			value_to_find = 3;

	try {
		cpp::easyfind(v, value_to_find);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	value_to_find = 42;

	try {
		cpp::easyfind(v, value_to_find);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
