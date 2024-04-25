#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <string>
#include <iostream>

namespace myspace {
	template<typename T>
	void	iter(T *arr, int arr_size, void (*f)(T const &)) {
		for (int i = 0; i < arr_size; i++) {
			f(arr[i]);
		}
	}

	template<typename T>
	void	writeOut(T s) {
		std::cout << s << std::endl;
	}
}

#endif
