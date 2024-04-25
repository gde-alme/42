#include "../inc/MutantStack.hpp"
#include <iostream>
#include <cstdlib>

int main() {
	MutantStack<int>	myStack;

	myStack.push(42);
	myStack.push(63);

	std::cout << std::endl << "top:" << myStack.top() << std::endl << std::endl;

	myStack.pop();

	std::cout << "curr stack size: " << myStack.size() << std::endl << std::endl;
	
	srand(time(NULL));
	for (int i = 0; i < 12; i++) {
		int	v = abs(i * rand() % 100);
		std::cout << "adding " << v << " to stack " << std::endl;
		myStack.push(v);
	}

	std::cout << std::endl << "===============Full Stack===============" << std::endl << std::endl;
	std::cout << myStack << std::endl;
	std::cout << "========================================" << std::endl;

	MutantStack<int>::iterator it = myStack.begin();
	//MutantStack<int>::iterator it_2 = myStack.end();

	std::cout << "1st value: " << *it << std::endl;
	it++;
	std::cout << "2nd value: " << *it << std::endl;  
	it--;
	std::cout << "1st value: " << *it << std::endl;
}
