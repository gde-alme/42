/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:22:02 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:22:03 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    if (VERBOSE)
        std::cout << "[DiamondTrap] default constructor called" << std::endl;
    this->_name = "Default";
    ClapTrap::setName(std::string("Default") + "_clap_name");
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    if (VERBOSE)
        std::cout << "[DiamondTrap] default constructor called" << std::endl;
    this->_name = name;
    this->setHitPoints(FragTrap::getHitPoints());
    this->setEnergyPoints(ScavTrap::getEnergyPoints());
    this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap & cp) : ClapTrap(cp), FragTrap(cp), ScavTrap(cp) {
    if (VERBOSE)
        std::cout << "[DiamondTrap] copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap & cp) {
    this->setName(cp.getName());
    this->_name = cp.getName();
    this->setHitPoints(cp.getHitPoints());
    this->setEnergyPoints(cp.getEnergyPoints());
    this->setAttackDamage(cp.getAttackDamage());
    return (*this);
}

void    DiamondTrap::attack(const std::string & target) {
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI() const {
    std::cout << "My name: " << this->_name << " and my scrapTrap name: " << this->getName() << std::endl;
}

std::string     DiamondTrap::getMyName() const {
    return (this->_name);
}