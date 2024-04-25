/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:22:34 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:22:35 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap	chad("hi");

	std::cout << "And his name is " << chad << std::endl;
	
	ScavTrap	chader("bye");
	
	std::cout << "And his name is " << chader << std::endl;

	ScavTrap	evenMchad(chader);

	evenMchad.setName(evenMchad.getName() + " lol");

	std::cout << "And his name is " << evenMchad << std::endl;
	
	chad.attack("goncalo");
	chader.setHitPoints(42);
	evenMchad.guardGate();

	FragTrap	chading("Community");

	std::cout << "And his name is " << chading << std::endl;

	FragTrap	chaden(chading);

	chaden.setName(chaden.getName() + " Service");
	std::cout << "And his name is " << chaden << std::endl;

	chaden.highFiveGuys();
}