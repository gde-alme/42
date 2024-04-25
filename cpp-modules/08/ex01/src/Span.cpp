#include "../inc/Span.hpp"

Span::Span() {
	if (VERBOSE)
		std::cout << "[Span] default constructor called" << std::endl;
}

Span::~Span() {
	if (VERBOSE)
		std::cout << "[Span] default destructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	if (VERBOSE)
		std::cout << "[Span] constructor called" << std::endl;
}

Span::Span(const Span &ref) {
	if (VERBOSE)
		std::cout << "[Span] copy constructor called" << std::endl;
	*this = ref;
}

Span	Span::operator=(const Span &ref) {
	if (this != &ref) {
		this->_N = ref._N;
		this->_arr = ref._arr;
	}
	return (*this);
}

void	Span::addNumber(int num) {
	if (this->_arr.size() >= _N)
		throw MaxCapacityEx;
	this->_arr.push_back(num);
}

void	Span::addNumbers(std::vector<int>::const_iterator i, std::vector<int>::const_iterator j) {
	if (this->_arr.size() + std::distance(i, j) > this->_N)
		throw MaxCapacityEx;
	this->_arr.insert(this->_arr.end(), i, j);
}

unsigned int	Span::longestSpan() {
	if (this->_N < 2)
		throw NoElementsEx;
	return (*std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end()));
}

unsigned int	Span::shortestSpan() {
	if (this->_N < 2)
		throw NoElementsEx;

	unsigned int	min_value = std::numeric_limits<int>::max();
	unsigned int	curr_value;

	for (int i = 0; i < (int)this->_arr.size(); i++) {
		for (int j = i + 1; j < (int)this->_arr.size(); j++) {
			 curr_value = static_cast<unsigned int>(abs(abs(this->_arr[i]) - abs(this->_arr[j])));
			 if (curr_value < min_value)
				 min_value = curr_value;
		}
	}
	return (min_value);
}

unsigned int	Span::getN() const {
	return (_N);
}

std::vector<int>	Span::getArr() const {
	return (_arr);
}

std::ostream	&operator<<(std::ostream &fd, const Span &ref) {
	for (int i = 0; i < (int)ref.getArr().size(); i++)
		fd << "[" << i << "] -> " << ref.getArr()[i] << std::endl;
	return (fd);
}
