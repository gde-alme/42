/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:16 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/24 19:11:40 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
    if (VERBOSE)
    std::cout << "[Dog] default constructor called" << std::endl;
    this->_type = "Dog";
}

Dog::Dog(const Dog & cp) : Animal(cp) {
    if (VERBOSE)
    std::cout << "[Dog] default copy constructor called" << std::endl;
}

Dog::~Dog() {
    if (VERBOSE)
    std::cout << "[Dog] default destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog & cp) {
    if (VERBOSE)
    std::cout << "[Dog] default copy operator overload called" << std::endl;
    this->_type = cp._type;
    return (*this);
}

void    Dog::makeSound() const {
    std::cout << "Dog custom sound" << std::endl;
}