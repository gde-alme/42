/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:46:59 by gde-alme          #+#    #+#             */
/*   Updated: 2023/04/24 16:47:00 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* to test: nums=$(suff -i 1-10000 -n 5000 | tr '\n' ' '); ./exec $nums */
int main(int argc, char *argv[]) {
	PmergeMe	sorter;

	if (argc < 3) {
		std::cout << "\n\tUsage:\n\n./PmergeMe int int int int ...\n" << std::endl;
		if (argc == 2)
			std::cout << "Array must have size at least 2 int\n" << std::endl;
		return (1);
	}

	try {
		sorter.parseInput(++argv);
		sorter.sortArray();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
