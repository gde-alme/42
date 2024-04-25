/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:00:56 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:00:57 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
    private:
        int     _fixedPointValue;
        static  const   int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &oldfpn);
        ~Fixed();
        Fixed &operator=(const Fixed &oldfpn);
        int     getRawBits() const;
        void    setRawBits(int const raw);
};

#endif