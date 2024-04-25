/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:24:50 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:24:51 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

# include <iostream>

# ifndef VERBOSE
# define VERBOSE true
# endif

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(const Animal & cp);
        /* virtual destructor so deleting each one is possible */
        virtual ~Animal();
        Animal &operator=(const Animal & cp);
        virtual std::string getType() const;
        virtual void    makeSound() const;
};

#endif