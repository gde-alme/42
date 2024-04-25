/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 02:03:20 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/19 02:03:22 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Default constructor */
Point::Point(void) : _x(0), _y(0) {
	//std::cout << "[POINT] Default constructor called" << std::endl;
}

/* Init x & y constructor */
Point::Point(const float v1, const float v2) : _x(v1), _y(v2) {
	//std::cout << "[POINT] Init values constructor called" << std::endl;
}

/* Copy constructor */
Point::Point(const Point &oldf) : _x(oldf._x), _y(oldf._y){
	//std::cout << "[POINT] Copy constructor called" << std::endl;
}

Point &Point::operator=(Point const &parent) {
	if (this != &parent) {
		this->setX(parent.getX());
		this->setY(parent.getY());
	}
	return (*this);
}

/* Destructor */
Point::~Point(void) {
}


/* Helper functions */
Fixed	Point::getX(void) const {
	return (this->_x);
}

Fixed	Point::getY(void) const {
	return (this->_y);
}

void	Point::setX(Fixed const &fnum) {
	(Fixed)this->_x = fnum;
}

void	Point::setY(Fixed const &fnum) {
	(Fixed)this->_y = fnum;
}