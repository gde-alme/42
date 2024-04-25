#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

# include <iostream>

# ifndef VERBOSE
# define VERBOSE true
# endif

template<typename T>
class Array {
	private:
		T 				*_arr;
		unsigned int	_n;	
	public:
		/* constructors */
		Array() : _arr(new T()), _n(0) {
			if (VERBOSE)
				std::cout << "[ArrayTemplate] default constructor called" << std::endl;
		};
		Array(unsigned int n) : _arr(new T[n]), _n(n) {
			if (VERBOSE)
				std::cout << "[ArrayTemplate] " << n << " size array created" << std::endl;
		};

		Array(const Array &ref) {
			if (VERBOSE)
				std::cout << "[ArrayTemplate] copy constructor called" << std::endl;
			if (this != &ref)
				*this = ref;
		};

		/* destructors */
		~Array() {
			delete [] this->_arr;
		};

		/* operators */
		Array	&operator=(const Array &ref) {
			if (this != &ref) {
				this->_arr = new T[ref.size()];
				this->_n = ref.size();
				for (unsigned int i = 0; i < ref._n; i++) {
					this->_arr[i] = ref._arr[i];
				}
			}
			return (*this);
		};

		T	&operator[](unsigned int idx) const {
			if (idx >= this->_n) {
				throw OutBundary;
			}
			return (this->_arr[idx]);
		}

		/* utils */
		unsigned int	size() const {
			return (this->_n);
		}

		/* exceptions */
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return ("index is out of boundary");
				}
		}OutBundary;
};

#endif
