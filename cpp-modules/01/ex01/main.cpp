/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:58 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:59 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main() {
	Zombie	*mob = zombieHorde(42, "Chad");
	int	i = -1;
	while (++i < 42)
		mob[i].announce();
	delete [] mob;
}
