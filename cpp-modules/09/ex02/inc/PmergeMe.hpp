/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <gde-alme@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:47:04 by gde-alme          #+#    #+#             */
/*   Updated: 2023/05/29 17:23:46 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

# ifndef VERBOSE
# define VERBOSE true
# endif

# ifndef THRESHOLD
# define THRESHOLD 200
# endif

# include <string>
# include <iostream>
# include <limits.h>
# include <ctype.h>
# include <exception>
# include <cmath>
# include <ctime>
# include <algorithm>
# include <vector>
# include <list>

/*
 *	PmergeMe:
 *		1. Divide the input array into subarrays of size n.
 *		2. If n < (int)log(input.size), use insertion sort to sort each subarray.
 *		3. Otherwise, recursively apply merge-insert sort to each subarray.
 *		4. Merge the sorted subarrays using the merge sort algorithm.
 * 	@parseInput:	Validate and tokenize input.
 * 	@merge_insert:	Sort array using merge-insert sort.
 */
class  PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &);
	
		void	parseInput(char **arr);
		void	sortArray();
		void	merge_insert_list(std::list<int> &arr);
		void	merge_insert_vector(std::vector<int> &);

		class	invalidTokenException : public std::exception {
			virtual const char *what() const throw() {
				return ("Invalid token in input");
			}
		}invalidToken;

	protected:

	private:
		std::vector<int>	_unsorted;
		std::list<int>		_lsorted;
		std::vector<int>	_vsorted;
		int			_size;
};

#endif
