/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:27 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 16:47:49 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <exception>

# ifndef VERBOSE
# define VERBOSE true
# endif


/*
 *	RPN class:
 *	@computeString:
 */
class RPN {
	public:
		RPN();
		RPN(const RPN &);
		~RPN();

		RPN	&operator=(const RPN &);

		int	computeString(std::string);
		class invalidTokenException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("\nInvalid Token in input\n");
				}
		}invalidToken;
	private:
		std::stack<int>	_stack;
};

#endif
