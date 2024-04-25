/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:26 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:27 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type) {
}

Weapon::~Weapon() {
}

const std::string&	Weapon::getType() {
	return (this->_type);
}

void	Weapon::setType(std::string _newtype) {
	this->_type = _newtype;
}
