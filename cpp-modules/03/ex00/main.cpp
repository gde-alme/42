/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:03:54 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 16:49:56 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap chad("Hello world");
	ClapTrap monkey(chad);
	chad.attack("goncalo");
	monkey.attack("edgar");
	chad.beRepaired(42);
}