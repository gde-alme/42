/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:03:44 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/20 12:34:41 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	if (VERBOSE)
		std::cout << "[ClapTrap] default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	if (VERBOSE)
		std::cout << "[ClapTrap] default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cp) {
	if (VERBOSE)
		std::cout << "[ClapTrap] copy constructor called" << std::endl;
	*this = cp;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &cp) {
	if (VERBOSE)
		std::cout << "[ClapTrap] copy overload operator called" << std::endl;
	this->_name = cp._name;
	this->_hitPoints = cp._hitPoints;
	this->_energyPoints = cp._energyPoints;
	this->_attackDamage = cp._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap() {
	if (VERBOSE)
		std::cout << "[ClapTrap] default destructor called" << std::endl;
}

std::string	ClapTrap::getName() const {
	return (this->_name);
}

int		ClapTrap::getHitPoints() const {
	return (this->_hitPoints);
}

int		ClapTrap::getEnergyPoints() const {
	return (this->_energyPoints);
}

int		ClapTrap::getAttackDamage() const {
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints) {
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints) {
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage) {
	this->_attackDamage = attackDamage;
}

std::ostream	&operator<<(std::ostream & ostreamf, ClapTrap const & cp) {
	ostreamf << cp.getName();
	return (ostreamf);
}

void    ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		return ;
	std::cout << "[ClapTrap] " << this->_name << " attacks " << target << " taking " << this->_attackDamage << std::endl;
	this->_energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
		return ;
	std::cout << "[ClapTrap] " << this->_name << " is repairing himself " << amount << " hitPoints" << std::endl;
	this->_hitPoints += amount;
}