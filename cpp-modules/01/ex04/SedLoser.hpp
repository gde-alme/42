/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:07 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/16 16:38:36 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SEDLOSER_HPP__
#define __SEDLOSER_HPP__

#include <iostream>
#include <fstream>
#include <sys/stat.h>

class SedLoser {
	public:
		SedLoser(void);
		~SedLoser(void);

		bool	openFile(std::string pathFile);
		bool	replace(std::string s1, std::string s2);
		std::string	parseLine(std::string rline, std::string s1, std::string s2);
		void	writeToFile(void);

	private:
		std::string fileName;
		std::string s1;
		std::string	s2;
		std::ifstream iFileStream;
		std::string	s3;
};

#endif /* __SEDLOSER_HPP__ */