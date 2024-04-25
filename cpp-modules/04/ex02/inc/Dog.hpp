/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:24:58 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/27 13:01:40 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain*  _myBrain;
    public:
        Dog();
        Dog(const Dog & cp);
        virtual ~Dog();
        Dog &operator=(const Dog & cp);
        void    makeSound() const;
        Brain   *getBrain() const;
};

#endif