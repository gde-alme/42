/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:01:25 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:01:26 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "[FIXED] default construtor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int num) {
	std::cout << "[FIXED] Int construtor called" << std::endl;
	/* simple bitshift */
	this->_fixedPointValue = num << this->_fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "[FIXED] Float construtor called" << std::endl;
	/* algo just bc */
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
		this->_fixedPointValue = oldfpn.getRawBits();
	return (*this);
}

int     Fixed::getRawBits() const {
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float     Fixed::toFloat() const {
	/* reverse of magic algo */
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt() const {
	/* reverse bitshift */
	return (this->_fixedPointValue >> this->_fractionalBits);
}

std::ostream	&operator<<(std::ostream &ostreamf, Fixed const &FixedC) {
	std::cout << "([FIXED] overload operator to output buffer) " << std::flush;
	ostreamf << FixedC.toFloat();
	return (ostreamf);
}