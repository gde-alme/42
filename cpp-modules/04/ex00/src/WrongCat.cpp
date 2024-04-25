/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:33 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/24 19:13:12 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
    if (VERBOSE)
        std::cout << "[WrongCat] default constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & cp) : WrongAnimal(cp){
    if (VERBOSE)
        std::cout << "[WrongCat] default copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    if (VERBOSE)
        std::cout << "[WrongCat] default destructor called" << std::endl;
}

WrongCat     &WrongCat::operator=(const WrongCat & cp) {
    if (VERBOSE)
        std::cout << "[WrongCat] copy overload operator called" << std::endl;
    this->_type = cp._type;
    return (*this);
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat wronging sound" << std::endl;
}