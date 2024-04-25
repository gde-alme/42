/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:00 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:02 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &gun): _name(name), _weapon(gun) {
}

HumanA::~HumanA() {
}

void	HumanA::Attack() {
	std::cout << this->_name << " attacks with their weapon " << this->_weapon.getType() << std::endl;
}
