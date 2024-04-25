/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:39 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:40 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	Weapon	club = Weapon("spike club");
	HumanA	chad("Chad", club);

	chad.Attack();
	club.setType("A better club");
	chad.Attack();
	Weapon	banana = Weapon("banana");
	HumanB	monkey("Monkey");

	monkey.setWeapon(banana);	
	monkey.Attack();
	banana.setType("a bigger banana");
	monkey.Attack();
}
