#ifndef __SPAN_HPP__
#define __SPAN_HPP__

# ifndef VERBOSE
# define VERBOSE true
# endif

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_arr;
		Span();
	public:
		Span(unsigned int N);
		~Span();
		Span(const Span &);
		Span	operator=(const Span &);

		unsigned int		getN() const;
		std::vector<int>	getArr() const;

		void	addNumber(int);
		void	addNumbers(std::vector<int>::const_iterator, std::vector<int>::const_iterator);

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		class MaxCapacityException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception thrown: vector size limit");
				};
		}MaxCapacityEx;

		class NoElementsException : std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception thrown: no elements to get Span");
				};
		}NoElementsEx;
};

std::ostream	&operator<<(std::ostream &, const Span &);

#endif
