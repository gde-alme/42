/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:13 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:21:14 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__

# include "Animal.hpp"

class Cat : public Animal {
    private:
    protected:
    public:
        Cat();
        Cat(const Cat & cp);
        ~Cat();
        Cat &operator=(const Cat & cp);
        void    makeSound() const ;
};

#endif