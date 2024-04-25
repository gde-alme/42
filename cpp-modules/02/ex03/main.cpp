/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:02:55 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 16:01:21 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Usage: ./bsp point_x_coordenate point_y_coordenate" << std::endl;
		return (0);
	}
	Point	a(42, 24);
	Point	p(2, 2);
	Point	d(4, 2);
	Point	c(3, 13);

	if (bsp(p, d, c, Point(atoi(argv[1]),atoi(argv[2]))))
		std::cout << "Yes it is" << std::endl;
	else
		std::cout << "Nop" << std::endl;
}