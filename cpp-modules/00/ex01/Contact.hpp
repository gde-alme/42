/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:22:18 by gde-alme          #+#    #+#             */
/*   Updated: 2023/01/31 12:14:42 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <iomanip>

class	Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;
		int	_index;
	public:
		Contact();
		~Contact();
		void	init(int index);
		std::string	_getInput(std::string prompt);
		void	preview(void);
		void	display(void);
		std::string	getPreview(std::string atributte);
};

#endif
