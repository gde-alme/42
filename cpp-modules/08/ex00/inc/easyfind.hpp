#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

# include <iostream>
# include <vector>
# include <algorithm>

namespace cpp {
	class NoOccurrenceFoundException : public std::exception {
		virtual const char *what() const throw() {
			return ("No occurrence found");
		};
	}NoOccurrF;

	template<typename T>
	void	easyfind(T v, int value_to_find) {
		std::vector<int>::iterator idx = std::find(v.begin(), v.end(), value_to_find);
		if ( idx != v.end())
			std::cout << "Value " << value_to_find << " was found at pos " <<  idx - v.begin() << std::endl;
		else
			throw NoOccurrF;
	};
}

#endif
