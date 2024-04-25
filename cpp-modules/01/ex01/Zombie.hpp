/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:59:09 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:59:10 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class	Zombie {
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
};

#endif
