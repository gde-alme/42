/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:46 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/11 03:00:46 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>

class Harl {
    public:
        Harl(void);
        ~Harl(void);
        void    complain(std::string level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};

#endif