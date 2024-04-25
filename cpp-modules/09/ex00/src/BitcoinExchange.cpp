/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:59 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 16:34:36 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	if (VERBOSE)
		std::cout << "[BitcoinExchange] default constructor called" << std::endl << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
	if (VERBOSE)
		std::cout << "[BitcoinExchange] copy constructor called" << std::endl;
	*this = ref;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &ref) {
	if (VERBOSE)
		std::cout << "[BitcoinExchange] copy overload operator called" << std::endl;
	this->_dataset = ref._dataset;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	if (VERBOSE)
		std::cout << "\n[BitcoinExchange] default destructor called" << std::endl;
}

bool	BitcoinExchange::__isValidCsvDataPoint(std::string str) const {

	if (std::count(str.begin(), str.end(), ',') != 1) return (false);
	return (std::isdigit(str[str.find(",") + 1]));
}

bool	BitcoinExchange::__isValidDate(std::string date) const {
	int	year, month, day;
	
	if (std::count(date.begin(), date.end(), '-') != 2) return (false);
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) return (false);
	if (year > 2023 || year < 2009) return (false);
	if (month > 12 || month < 1) return (false);
	if (day > 31 || day < 1) return (false);
	return (true);
}

t_date	BitcoinExchange::_parseDate(std::string date) const {
	if (!__isValidDate(date)) throw invalidDate;

	int	year, month, day;
	
	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	t_date	newDate = {
		.year	= year,
		.month	= month,
		.day	= day
	};
	return (newDate);
}



void	BitcoinExchange::parseCsv(std::string pathToFile) {
	std::ifstream	fd(pathToFile.c_str());
	std::string	curr_line;
	t_date		date;
	float		value;
	int		line = 2;

	if (fd.is_open()) {
		std::getline(fd, curr_line);
		while (std::getline(fd, curr_line)) {
			if (__isValidCsvDataPoint(curr_line)) {
				try {
					date = _parseDate(curr_line.substr(0, curr_line.find(',')));
				} catch (std::exception &e) { std::cout << "Error: invalid date in line [" << line << "] in file [" << pathToFile << "]" << std::endl;; fd.close(); return ;}
				value = atof(curr_line.substr(curr_line.find(',') + 1).c_str());
				_dataset[date] = value;
			}
			else { 	
				std::cout << "Error: csv file: line [" << line << "]: " << std::flush; 
				fd.close();
				throw invalidCsvDataPoint;
			}
			line++;
		}
		fd.close();
	} else {
		std::cerr << "Error: Failed to open file: \"" << pathToFile << "\": " << std::flush;
		throw	openFileException;
	}
}

std::time_t	BitcoinExchange::_dateToUnixTime(t_date date) const {
	std::tm	tminf	= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	tminf.tm_year	= date.year - 1900;
	tminf.tm_mon	= date.month - 1;
	tminf.tm_mday	= date.day;
	tminf.tm_isdst	= -1;
	
	std::time_t	unix_time = std::mktime(&tminf);

	return (unix_time);
}

float	BitcoinExchange::getValue(std::string date) const {
	t_date	sdate;
	try { sdate = _parseDate(date); } catch (std::exception &e) { throw; }

	std::map<t_date, float>::const_iterator fit = _dataset.find(sdate);
	if (fit != _dataset.end())
		return (fit->second);

	std::map<t_date, float>::const_iterator it = _dataset.begin();
	std::map<t_date, float>::const_iterator it_save = it;
	std::time_t	sdate_t = _dateToUnixTime(sdate);
	for (;it != _dataset.end(); it++) {
		if (_dateToUnixTime(it->first) < sdate_t)
			it_save = it;
		else
			return (it_save->second);
	}
	it--;
	return (it->second);
}

float	BitcoinExchange::_getAmountBtc(std::string line) const {
	if (std::count(line.begin(), line.end(), '|') != 1) throw invalidEvalDateValue;
	line = line.substr(line.find('|') + 1);
	float	amount = atof(line.c_str());
	if (amount < 0.0f || amount > 1000.0f) throw invalidEvalDateValue;
	return (amount);
}

void	BitcoinExchange::parseEval(std::string pathToFile) const {
	std::ifstream	fd(pathToFile.c_str());
	std::string	curr_line;
	t_date		cdate;
	int		line = 1;
	double		btcA;
	double		btcV;

	if (fd.is_open()) {
		while (std::getline(fd, curr_line)) {
			if (line == 1 && curr_line.compare("date | value") == 0)
				continue ;
			try { btcA = (double)_getAmountBtc(curr_line); } catch (std::exception &e) { std::cout << "Invalid amount of btc" << std::endl; continue ; }
			try { btcV = (double)getValue(curr_line); } catch (std::exception &e) { std::cout << e.what() << std::endl; continue ; }
			cdate = _parseDate(curr_line);
			std::cout << std::setw(4) << std::setfill('0') << cdate.year << "-"
				<< std::setw(2) << std::setfill('0') << cdate.month << "-"
				<< std::setw(2) << std::setfill('0') << cdate.day << std::flush;
			std::cout << std::fixed << std::setprecision(4) << " => " << btcV * btcA << std::endl;
			line++;
		}
		fd.close();
	} else {
		std::cerr << "Error: Failed to open file: \"" << pathToFile << "\": " << std::flush;
		throw	openFileException;
	}
	
}
