/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:26 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:27 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]){
    Harl Marvin;

    if (argc == 2)
        Marvin.complain(argv[1]);
    else
        std::cout << "Usage: ./Marvin (debug || info || warning || error)" << std::endl;
}