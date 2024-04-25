/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:02:38 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 15:57:20 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed abs(Fixed a) {
	if ((a < Fixed(0)) == true)
		return (a * -1);
	return (a);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	/* 1. Calculate area of triangle formed by the 3 points */
	Fixed ga = Fixed(0.5f) * abs((a.getX() * (b.getY() - c.getY())) + \
		(b.getX() * (c.getY() - a.getY())) + \
		(c.getX() * (a.getY() - b.getY())));

	/* 2. Calculate area of the three triangles formed by the point 
		and each of the sides of the original triangle */
	Fixed a1 = Fixed(0.5f) * abs(point.getX() * (b.getY() - c.getY()) + \
		(b.getX() * (c.getY() - point.getY())) + \
		(c.getX() * (point.getY() - b.getY())));

	Fixed a2 = Fixed(0.5f) * abs(a.getX() * (point.getY() - c.getY()) + \
		(point.getX() * (c.getY() - a.getY())) + \
		(c.getX() * (a.getY() - point.getY())));

	Fixed a3 = Fixed(0.5f) * abs(a.getX() * (b.getY() - point.getY()) + \
		(b.getX() * (point.getY() - a.getY())) + \
		(point.getX() * (a.getY() - b.getY())));

	/* 3. If the sum of the three triangles is equal to the area of 
		the original triangle, then the point is inside */
	return (a1 + a2 + a3 == ga);
	//std::cout << "triangle area: " << ga.toFloat() << std::endl;
	//std::cout << "triangle1 area: " << a1.toFloat() << std::endl;
	//std::cout << "triangle2 area: " << a2.toFloat() << std::endl;
	//std::cout << "triangle3 area: " << a3.toFloat() << std::endl;
}