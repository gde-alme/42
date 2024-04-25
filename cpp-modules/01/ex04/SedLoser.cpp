/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 03:00:03 by gde-alme          #+#    #+#             */
/*   Updated: 2023/03/16 16:39:58 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLoser.hpp"
#include <cstdlib>

/* Constructor */
SedLoser::SedLoser(void) {
}

/* Destructor */
SedLoser::~SedLoser(void) {
}

std::string	SedLoser::parseLine(std::string rline, std::string s1, std::string s2) {
	if (rline == "")
		return ("");
	size_t	s1Len = s1.length();
	size_t		pos = 0;
	while (pos < rline.length()) {
		if (rline.compare(pos, s1Len, s1) == 0) {
			rline.erase(pos, s1Len);
			rline.insert(pos, s2);
			pos += s2.length();
		}
		else
			pos++;
	}
	return (rline);
}

bool	SedLoser::openFile(std::string pathFile) {
	struct stat sb;
	const char *cfile = &pathFile[0];
	if (this->iFileStream.is_open())
		this->iFileStream.close();
	if (pathFile == "" || stat(&pathFile[0], &sb) != 0)
		return (false);
	else {
		this->iFileStream.open(cfile);
		this->fileName = pathFile;
		return (true);
	}
}

bool	SedLoser::replace(std::string s1, std::string s2) {
	std::string	rline;
	std::string	nline = "";
	while (std::getline(this->iFileStream, rline)) {
		rline = SedLoser::parseLine(rline, s1, s2);
		nline += rline;
		nline += "\n";
	}
	this->s3 = nline;
	this->iFileStream.close();
	return (true);
}

void	SedLoser::writeToFile(void) {
	std::ofstream	oFileStream;
	std::string		outPathFile;

	outPathFile = this->fileName;
	outPathFile += ".replace";

	const char	*cco = &outPathFile[0];

	oFileStream.open(cco);
	oFileStream << this->s3;
	oFileStream.close();
}