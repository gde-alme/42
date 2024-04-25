/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:59:14 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:59:15 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	int	i = -1;
	Zombie	*mob = new Zombie[N];
	while (++i < N) {
		mob[i].setName(name);
	}
	return (mob);
}
