/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:27 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/24 19:13:04 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    if (VERBOSE)
        std::cout << "[WrongAnimal] was born by default constructor" << std::endl; 
    this->_type = "Monster";
}

WrongAnimal::WrongAnimal(const WrongAnimal & cp) {
    if (VERBOSE)
        std::cout << "[WrongAnimal] was born by default copy constructor" << std::endl;
    *this = cp;
}

WrongAnimal  & WrongAnimal::operator=(const WrongAnimal & cp) {
    this->_type = cp._type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    if (VERBOSE)
        std::cout << "[WrongAnimal] was killed by default destructor" << std::endl; 
}

std::string WrongAnimal::getType() const {
    return (this->_type);
}

void    WrongAnimal::makeSound() const {
    std::cout << "Random WrongAnimal sound" << std::endl;
}