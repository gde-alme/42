/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:33 by gde-alme          #+#    #+#             */
/*   Updated: 2023/04/24 16:47:34 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int main(int argc, char **argv) {
	RPN	myRpn;
	RPN	cp = myRpn;

	if (argc == 2) {
		try {
			myRpn.computeString(argv[1]);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (0);
		}
	}
}
