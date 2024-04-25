/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:22:51 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:22:52 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() {
    if (VERBOSE)
        std::cout << "[ScavTrap] default constructor called" << std::endl;
    this->setName("Default");
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) {
    if (VERBOSE)
        std::cout << "[ScavTrap] constructor called" << std::endl;
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap & cp) : ClapTrap(cp) {
    if (VERBOSE)
        std::cout << "[ScavTrap] copy constructor called" << std::endl;
    this->setName(cp.getName());
    this->setHitPoints(cp.getHitPoints());
    this->setEnergyPoints(cp.getEnergyPoints());
    this->setAttackDamage(cp.getAttackDamage());
}

ScavTrap    &ScavTrap::operator=(const ScavTrap & cp) {
    if (VERBOSE)
        std::cout << "[ScavTrap] copy overload operator called" << std::endl;
    this->setName(cp.getName());
    this->setHitPoints(cp.getHitPoints());
    this->setEnergyPoints(cp.getEnergyPoints());
    this->setAttackDamage(cp.getAttackDamage());
    return (*this);
}

ScavTrap::~ScavTrap() {
    if (VERBOSE)
        std::cout << "[ScavTrap] destructor called" << std::endl;
}

void    ScavTrap::attack(const std::string & target) {
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
		return ;
	std::cout << "[ScavTrap] " << this->getName() << " attacks " << target << " taking " << this->getAttackDamage() << " and has a diff msg" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void    ScavTrap::guardGate() {
	if (this->getHitPoints() <= 0 || this->getEnergyPoints() <= 0)
		return ;
    std::cout << "[ScavTrap] " << this->getName() << " is now in Gate keeper mode (whatever it is)" << std::endl;
}