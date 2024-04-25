/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:12 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:13 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void	HumanB::setWeapon(Weapon &gun) {
	this->_weapon = &gun;
}

void	HumanB::Attack() {
	std::cout << this->_name << " attacks with their weapon " << this->_weapon->getType() << std::endl;
}
