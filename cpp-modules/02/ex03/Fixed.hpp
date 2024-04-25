/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:02:50 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 16:31:43 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <iostream>
# include <cmath>

# ifndef VERBOSE
# define VERBOSE true
# endif

class Fixed {
    private:
        int     _fixedPointValue;
        static  const   int		_fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &oldfpn);
        ~Fixed();
        Fixed &operator=(const Fixed &oldfpn);
        bool    operator>(const Fixed &opponent) const;
        bool    operator<(const Fixed &opponent) const;
        bool    operator>=(const Fixed &opponent) const;
        bool    operator<=(const Fixed &opponent) const;
        bool    operator==(const Fixed &opponent) const;
        bool    operator!=(const Fixed &opponent) const;
        Fixed   operator+(const Fixed &opponent) const;
        Fixed   operator-(const Fixed &opponent) const;
        Fixed   operator*(const Fixed &opponent) const;
        Fixed   operator/(const Fixed &opponent) const;
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);
        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;
        /*
        Static Function Members
            by declaring a function member as static, you make it independent of any
            particular object of the class. A static member function can be called 
            even if no objects of the class exist and the static functions are accessed
            using only the class name and the scope resolution operator ::.
        */
        static Fixed   &min(Fixed &a, Fixed &b);
        static const Fixed   &min(const Fixed &a, const Fixed &b);
        static Fixed   &max(Fixed &a, Fixed &b);
        static const Fixed   &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &ostreamf, Fixed const &FixedC);

#endif