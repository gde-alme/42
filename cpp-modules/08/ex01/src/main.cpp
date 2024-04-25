#include "../inc/Span.hpp"

int main() {
	Span mySpan(42);

	try {
		mySpan.addNumber(7);
		mySpan.addNumber(12);
		mySpan.addNumber(65);
		mySpan.addNumber(1442);
	} catch (const Span::MaxCapacityException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nSpan values:\n" << mySpan << std::endl;

	try {
		std::cout << "Longest Span: " << mySpan.longestSpan() << std::endl;
		std::cout << "Shortest Span: " << mySpan.shortestSpan() << std::endl;
	} catch (const Span::NoElementsException &e) {
		std::cout << e.what() << std::endl;
	}

	std::vector<int>	a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);

	try {
		mySpan.addNumbers(a.begin(), a.end());
	} catch (const Span::MaxCapacityException &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n\nSpan values:\n" << mySpan << std::endl;

	return (0);
}
