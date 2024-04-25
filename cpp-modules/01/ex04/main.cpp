/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:21 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/16 16:35:51 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLoser.hpp"

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Usage: ./SedLoser pathToFile needle replace" << std::endl;
		return (1);
	}

	SedLoser myLoser;

	std::string	pathToFile = argv[1];
	std::string	needle = argv[2];
	std::string	replace = argv[3];

	if (pathToFile.empty() || needle.empty() || replace.empty()) {
		std::cout << "Error: bad arguments" << std::endl;
		return (2);
	}

	if (!(myLoser.openFile(pathToFile))) {
		std::cout << "Error: no such file or directory" << std::endl;
		return (1);
	}
	myLoser.replace(needle, replace);
	myLoser.writeToFile();
}