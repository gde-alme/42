/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:03:25 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:03:26 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

# include "Fixed.hpp"

# include <iostream>

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
		Point(const float v1, const float v2);
		Point(const Point &oldp);
		Point	&operator=(const Point &parent);
        ~Point(void);
		Fixed	getX(void) const;
		Fixed	getY(void) const;
		void	setX(Fixed const &fnum);
		void	setY(Fixed const &fnum);
};

#endif