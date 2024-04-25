/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:25:22 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/07 19:50:44 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string	Contact::_getInput(std::string prompt) {
	std::string	input = "";
	bool	valid = false;

	while (!valid) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			valid = true;
		else {
			std::cout << "Invalid input!" << std::endl;
		}
		std::cin.clear();
		//std::cin.ignore(10000, '\n');
	}
	return (input);
}

void	Contact::init(int index) {
	this->_firstname = this->_getInput("Enter first name: ");
	this->_lastname = this->_getInput("Enter last name: ");
	this->_nickname = this->_getInput("Enter nickname: ");
	this->_phonenumber = this->_getInput("Enter phone number: ");
	this->_darkestsecret = this->_getInput("Enter darkest secret: ");
	this->_index = index;
}

std::string	Contact::getPreview(std::string atributte) {
	std::string	resized;

	if (atributte.length() > 10) {
		resized = atributte.substr(0, 10);
		resized[9] = '.';
	}
	else
		resized = atributte.substr( 0, atributte.length());
	return (resized);
}

void	Contact::preview(void) {
	std::cout << "\t|" << std::setw(10) << this->_index  + 1 << "|" << std::setw(10) << this->getPreview(this->_firstname) \
		<< "|" << std::setw(10) << this->getPreview(this->_lastname) << "|" << std::setw(10) \
		<< this->getPreview(this->_nickname) << "|" << std::endl;
}

void	Contact::display(void) {
	std::cin.ignore(10000, '\n');
	std::cout << "\t" << std::setw(20) << "First Name -> " << this->_firstname << std::endl;
	std::cout << "\t" << std::setw(20) << "Last Name -> " << this->_lastname << std::endl;
	std::cout << "\t" << std::setw(20) << "Nick Name -> " << this->_nickname << std::endl;
	std::cout << "\t" << std::setw(20) << "Phone Number -> " << this->_phonenumber << std::endl;
	std::cout << "\t" << std::setw(20) << "Darkest Secret -> " << this->_darkestsecret << std::endl;
}