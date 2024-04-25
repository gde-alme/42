/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:39 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:40 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "Harl.h"

/* Public func */
Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void    Harl::complain(std::string level) {
   
    /* List funcs names in array of strings */
    std::string complainFuncs[] = {
        "debug",
        "info",
        "warning",
        "error"
    };
    /* Save each func addr as func pointer in array of func pointers */
    void    (Harl::*complainPtr[]) (void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int j = 0;

    switch (hashHit(level)) {
        case debugc:
            j = 0;
            break ;
        case infoc:
            j = 1;
            break ;
        case warningc:
            j = 2;
            break ;
        case errorc:
            j = 3;
            break ;
        case NO_LEVEL:
            j = -1;
            break ;
    }
    for (int i = 0; i <= j; i++) {
        void (Harl::*choosencomplain)(void) = complainPtr[i];
            (this->*choosencomplain)();
    }
}

/* Private func */
void    Harl::debug(void) {
    std::cout << std::endl << "[DEBUG]" << std::endl;
    std::cout << "Debuging this is such a waste of my planet sized brain, said Marvin" << std::endl << std::endl;
}

void    Harl::info(void) {
    std::cout << std::endl << "[INFO]" << std::endl;
    std::cout << "Can't believe Marvin's tasks are so mundane... " << std::endl << std::endl;
}

void    Harl::warning(void) {
    std::cout << std::endl << "[WARNING]" << std::endl;
    std::cout << "One day Marvin might just do it. Not a life for such a piece of engineering!" << std::endl << std::endl;
}

void    Harl::error(void) {
    std::cout << std::endl << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! Get me Zaphod Beeblebrox NOW!!" << std::endl << std::endl;
}