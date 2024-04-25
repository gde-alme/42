/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:52 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 15:41:11 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Error: Invalid Usage: ./btc file_to_parse" << std::endl;
		return (1);
	}

	BitcoinExchange	btcExcApi;

	try {
		btcExcApi.parseCsv("data.csv");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (0);
	}
	try {
		btcExcApi.parseEval(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (0);
	}
	return (0);
}
