/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:25:05 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:25:06 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() {
    if (VERBOSE)
        std::cout << "[Animal] was born by default constructor" << std::endl; 
    this->_type = "Frank";
}

Animal::Animal(const Animal & cp) {
    if (VERBOSE)
        std::cout << "[Animal] was born by default copy constructor" << std::endl;
    *this = cp;
}

Animal  & Animal::operator=(const Animal & cp) {
    this->_type = cp._type;
    return (*this);
}

Animal::~Animal() {
    if (VERBOSE)
        std::cout << "[Animal] was killed by default destructor" << std::endl; 
}

std::string Animal::getType() const {
    return (this->_type);
}

void    Animal::makeSound() const {
    std::cout << "Random animal sound" << std::endl;
}