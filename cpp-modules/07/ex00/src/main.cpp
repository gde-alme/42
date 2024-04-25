#include <iostream>
#include "../inc/whatever.hpp"

class Awesome
{
public:
Awesome(void) : _n(0) {}
Awesome( int n ) : _n( n ) {}
Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); } bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); } bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); } bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); } bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); } bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); } int get_n() const { return _n; }
private:
int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }




int main( void ) {
	int a = 2;
	int b = 3;

	Whatever::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << Whatever::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << Whatever::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	Whatever::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << Whatever::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << Whatever::max( c, d ) << std::endl;

	
	Awesome	e(42), f(24);

	Whatever::swap(a,b);
	std::cout << "min( c, d ) = " << Whatever::min( e, f ) << std::endl;
	std::cout << "max( c, d ) = " << Whatever::max( e, f ) << std::endl;

	return 0;
}
