/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:00:50 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:00:51 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "[FIXED] construtor called" << std::endl;
    this->_fixedPointValue = 0;
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
    std::cout << "[FIXED] getRawBits function called" << std::endl;
    return (this->_fixedPointValue);
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "[FIXED] setRawBits function called" << std::endl;
    this->_fixedPointValue = raw;
}