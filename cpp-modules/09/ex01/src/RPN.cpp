/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:22 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 16:46:54 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() {
	if (VERBOSE)
		std::cout << "[RPN] default constructor called" << std::endl;
}

RPN::RPN(const RPN &ref) {
	if (VERBOSE)
		std::cout << "[RPN] default constructor called" << std::endl;
	*this = ref;
}

RPN	&RPN::operator=(const RPN &ref) {
	if (this != &ref) {
	}
	return (*this);
}

RPN::~RPN() {
	if (VERBOSE)
		std::cout << "[RPN] default destructor called" << std::endl;
}

bool	is_valid(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::computeString(std::string rpn_string) {
	//double	result;
	char	c;
	int	num;

	std::istringstream iss(rpn_string);
	while (iss.get(c)) {
		if (std::isdigit(c)) {
			iss.putback(c);
			iss >> num;
			if (num > 10 || num < 0) throw	invalidToken;
			_stack.push(num);
		} else if (std::isspace(c)) {
			continue ;
		} else {
			if (!is_valid(c)) throw	invalidToken;
			if (_stack.size() < 2) throw invalidToken;
			num = _stack.top();
			_stack.pop();
			if (c == '+') {
				num += _stack.top();
			} else if (c == '-') {
				num = _stack.top() - num;
			} else if (c == '*') {
				num *= _stack.top();
			} else {
				num = _stack.top() / num;
			}
			_stack.pop();
			_stack.push(num);
		}
	}
	if (_stack.size() > 1) { std::cout << "Invalid arithmetix expression" << std::endl; return 1; }
	num = _stack.top();
	_stack.pop();
	std::cout << "\nrpn = " << num << std::endl << std::endl;
	return (num);
}
