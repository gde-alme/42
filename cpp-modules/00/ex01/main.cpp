/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:21:38 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/07 19:53:39 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main() {
	PhoneBook	phoneb;
	std::string		input = "";
	bool	valid;

	phoneb.welcome();
	while (input.compare("EXIT")) {
		if (input.compare("ADD") == 0)
			phoneb.add_cc();
		else if (input.compare("SEARCH") == 0)
			phoneb.search_cc();
		valid = false;
		while (!valid) {
			std::cout << "> " << std::flush;
			std::getline(std::cin, input);
			for (int i = 0; i < (int)input.length(); i++) { input[i] = (char)std::toupper(input[i]); }
			if (std::cin.good() && !input.empty() && input.find(32) > 999 && (\
				input.compare("EXIT") == 0 || input.compare("ADD") == 0 || input.compare("SEARCH") == 0))
				valid = true;
			else {
				//std::cin.ignore(10000, '\n');
				std::cout << "Not valid input!" << std::endl;
			}
			std::cin.clear();
		}
	}
	return (0);
}