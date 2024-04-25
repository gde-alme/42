/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:31 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:33 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define	WEAPON_HPP

#include <iostream>

class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string&	getType(void);
		void	setType(std::string _type);
};

#endif
