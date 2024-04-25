/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:49 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:50 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]){
    Harl Marvin;

    if (argc == 2)
        Marvin.complain(argv[1]);
    else
        std::cout << "Usage: ./harlFilter (debug || info || warning || error)" << std::endl;
}