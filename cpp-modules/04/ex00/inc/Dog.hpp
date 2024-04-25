/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:19 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:21:20 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__

# include "Animal.hpp"

class Dog : public Animal {
    private:
    public:
        Dog();
        Dog(const Dog & cp);
        ~Dog();
        Dog &operator=(const Dog & cp);
        void    makeSound() const;
};

#endif