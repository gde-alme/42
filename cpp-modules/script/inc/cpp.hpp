#ifndef __CPP_HPP__
#define __CPP_HPP__

# include <iostream>
# include <fstream>
# include <sys/stat.h>

# ifndef LOCALPATH
# define LOCALPATH "/home/gde-alme/"
# endif

/*
 *	Cpp:
 *	@createClass:	create a basic class hpp and cpp in orthodox format
 * */

class Cpp {
	public:
		Cpp() {};
		~Cpp() {};

		void	createClass(std::string class_name);
		void	initEnv();
	protected:
		std::string	_parseLine(std::string line, std::string class_name);
};

#endif
