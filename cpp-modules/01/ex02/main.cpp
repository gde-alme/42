/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 02:58:49 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 02:58:50 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using	std::cout;
using	std::endl;

int	main() {
	std::string helloWorld = "HI THIS IS BRAIN";
	std::string	*stringPTR = &helloWorld;
	std::string	&stringREF = helloWorld;

	cout << "\n• String address -> " << &helloWorld << endl << endl;
	cout << "• StringPTR helds -> " << stringPTR << " adress" << endl << endl;
	cout << "• StringREF helds -> " << &stringREF << " adress" << endl << endl;

	cout << "• Stack string holds value: " << helloWorld << endl << endl;
	cout << "• StringPTR points to value: " << *stringPTR << endl << endl;
	cout << "• StringREF points to value: " << stringREF << endl << endl;
}
