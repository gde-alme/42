/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:24:55 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/27 13:01:14 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain*  _myBrain;
    protected:
    public:
        Cat();
        Cat(const Cat & cp);
        virtual ~Cat();
        Cat &operator=(const Cat & cp);
        void    makeSound() const;
        Brain   *getBrain() const;
};

#endif