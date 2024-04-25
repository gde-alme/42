/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:03:49 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/20 10:42:43 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# ifndef VERBOSE
# define VERBOSE true
# endif 

# include <string>
# include <iostream>

class ClapTrap {
    private:
        std::string _name;
        int     _hitPoints;
        int     _energyPoints;
        int     _attackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &cp);
		ClapTrap	&operator=(const ClapTrap &cp);
        ~ClapTrap();
		std::string getName() const;
		int     getHitPoints() const;
		int     getEnergyPoints() const;
		int     getAttackDamage() const;
        void    setName(std::string name);
        void    setHitPoints(int hitPoints);
        void    setEnergyPoints(int energyPoints);
        void    setAttackDamage(int attackDamage);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};

std::ostream	&operator<<(std::ostream & ostreamf, ClapTrap const & cp);

#endif