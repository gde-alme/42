/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:01:46 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:01:47 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "[FIXED] default construtor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "[FIXED] Int construtor called" << std::endl;
	this->_fixedPointValue = num << this->_fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "[FIXED] Float construtor called" << std::endl;
	this->_fixedPointValue = roundf(num * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &oldfpn) {
	std::cout << "[FIXED] copy construtor called" << std::endl;
	this->_fixedPointValue = oldfpn._fixedPointValue;
}

Fixed::~Fixed() {
	std::cout << "[FIXED] destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &oldfpn) {
	std::cout << "[FIXED] copy assignment operator called" << std::endl;
	if (this != &oldfpn)
		this->setRawBits(oldfpn.getRawBits());
	return (*this);
}

int     Fixed::getRawBits() const {
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float     Fixed::toFloat() const {
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt() const {
	return (this->_fixedPointValue >> this->_fractionalBits);
}

/* operators overload */

/* output stream */
std::ostream	&operator<<(std::ostream &ostreamf, Fixed const &FixedC) {
	ostreamf << FixedC.toFloat();
	return (ostreamf);
}

/* Comparison operators */
bool	Fixed::operator>(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() > opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() > opponent.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() < opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() > opponent.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() >= opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() >= opponent.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() <= opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() <= opponent.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() == opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() == opponent.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &opponent) const {
	if (opponent._fractionalBits != this->_fractionalBits) {
		if (this->toFloat() != opponent.toFloat())
			return (true);
		return (false);
	}
	if (this->getRawBits() != opponent.getRawBits())
		return (true);
	return (false);
}

/* Arithmetic operators */
Fixed	Fixed::operator+(const Fixed &buddy) const {
	return(Fixed(this->toFloat() + buddy.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &buddy) const {
	return(Fixed(this->toFloat() - buddy.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &buddy) const {
	return(Fixed(this->toFloat() * buddy.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &buddy) const {
	return(Fixed(this->toFloat() / buddy.toFloat()));
}

/* Increment / decrement operators */

/* Prefix increment */
Fixed	&Fixed::operator++(void) {
	this->_fixedPointValue++;
	return (*this);
}

/* Postfix increment */
Fixed	Fixed::operator++ (int) {
	Fixed	tmp(*this);
	tmp.setRawBits(this->_fixedPointValue++);
	return (tmp);
}

/* Prefix decrement */
Fixed	&Fixed::operator--(void) {
	this->_fixedPointValue--;
	return (*this);
}

/* Postfix decrement */
Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	tmp.setRawBits(this->_fixedPointValue--);
	return (tmp);
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}