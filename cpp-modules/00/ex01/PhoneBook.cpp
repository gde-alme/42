/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:21:17 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/07 19:54:33 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::welcome(void) {
	this->_indexsize = 0;
	std::cout << "\t-------------------------------------" << std::endl;
	std::cout << "\tThis is your awesome PhoneBook" << std::endl;
	std::cout << "\t-------------------------------------" << std::endl;
	std::cout << "\tOPTIONS:" << std::endl << std::endl;;
	std::cout << "\tADD" << std::endl;
	std::cout << "\tSEARCH" << std::endl;
	std::cout << "\tEXIT" << std::endl;
	std::cout << "\t-------------------------------------" << std::endl;
}

void	PhoneBook::add_cc(void) {
	this->_contacts[this->_indexsize % 8].init(this->_indexsize % 8);
	if (this->_indexsize <= 7)
		this->_indexsize++;
}

void	PhoneBook::printContacts(void) {
	int	index = 0;

	std::cout << "\t ___________________________________________ " << std::endl;
	std::cout << "\t|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "\t|----------|----------|----------|----------|" << std::endl;
	while (index < this->_indexsize && this->_indexsize != 0) {
		this->_contacts[index].preview();
		index++;
	}
	std::cout << "\t -------------------------------------------" << std::endl;
}

void	PhoneBook::search_cc(void) {
	int	index = -1;
	bool	valid = false;

	this->printContacts();
	if (this->_indexsize == 0)
		return ;
	while (!valid) {
		std::cout << "Insert contact index: " << std::flush;
		std::cin >> index;
		if (std::cin.good() && (index > 0 && index < this->_indexsize + 1)) {
			valid = true;
			index--;
		}
		else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Must be a valid index!" << std::endl;
		}
		std::cin.clear();
	}
	this->_contacts[index].display();
}
