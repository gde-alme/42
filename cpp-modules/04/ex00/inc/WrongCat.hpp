/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:21:36 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/23 14:21:37 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    private:
    protected:
    public:
        WrongCat();
        WrongCat(const WrongCat & cp);
        ~WrongCat();
        WrongCat &operator=(const WrongCat & cp);
        void    makeSound() const ;
};

#endif