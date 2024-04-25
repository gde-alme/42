/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:24:52 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/27 12:25:44 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

# include <string>
# include <iostream>

# ifndef VERBOSE
# define VERBOSE true
# endif

class Brain {
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain & cp);
        ~Brain();
        Brain & operator=(const Brain & cp);
        std::string getIdea(int index) const ;
        void    addIdea(std::string idea);
};

#endif