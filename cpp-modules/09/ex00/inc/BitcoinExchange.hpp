/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:05 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 15:37:30 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <iomanip>

# ifndef VERBOSE
# define VERBOSE true
# endif

/*
 *	Struct s_date:
 *	@data:		year, month, day.
 *	@operator<:	operator for map<t_date, T>
 */
 typedef struct s_date {
 	int	year;
	int	month;
	int	day;

	bool operator<(const s_date &ref) const {
		if (year < ref.year) return true;
    		if (year == ref.year) {
			if (month < ref.month) return true;
			if (month == ref.month) return (day < ref.day);
		}
		return (false);
  	}	
}t_date;

/*
 *	BitcoinExchange class: 
 *	@parseCsv:	populates a map<time_since_epoch, value> with data from a data.csv file.
 *	@getValue:	retrieves each given date to the corresponding value. 
 *	@parseEval:	iterates through a txt file calling getValue for each valid date * nb_of_btc.
 */
class BitcoinExchange {
	private:
		std::map<t_date, float>	_dataset;
	protected:
		bool	__isValidDate(std::string) const;
		bool	__isValidCsvDataPoint(std::string) const;
		t_date	_parseDate(std::string) const;
		std::time_t	_dateToUnixTime(t_date) const;
		float	_getAmountBtc(std::string line) const;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &);
		BitcoinExchange	&operator=(const BitcoinExchange &);

		~BitcoinExchange();

		void	parseCsv(std::string pathToFile);
		float	getValue(std::string date) const;
		void	parseEval(std::string pathToFile) const;

		class openFileException : public std::exception {
			virtual const char *what() const throw() {
				return("Can't solve file name");
			}
		}openFileException;

		class invalidCsvDataPoint : public std::exception {
			virtual const char *what() const throw() {
				return("Invalid csv data point");
			}
		}invalidCsvDataPoint;
		
		class invalidDate : public std::exception {
			virtual const char *what() const throw() {
				return("Invalid date");
			}
		}invalidDate;

		class invalidEvalDateValue : public std::exception {
			virtual const char *what() const throw() {
				return("Can't solve date and/or btc value");
			}
		}invalidEvalDateValue;
};

#endif
