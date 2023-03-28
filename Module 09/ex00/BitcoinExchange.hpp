#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <stdexcept>
# include <fstream>

# include <map>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		void	setPriceDB(std::string date, float value);
		void	printResult();


		// std::string	getFileContent(std::string file);
		void	getFileContent(std::string file);
		bool	checkDateValidity(std::string line);
		bool	checkTitle(std::string line, std::string fileName);


		class fileError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Opening file impossible.");
				}
		};

		class maxIntError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Number too big.");
				}
		};

		class argsError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Arguments error.");
				}
		};

		class impossibleError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Operation impossible.");
				}
		};

		class invalidDataError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Invalid characters.");
				}
		};

		class DuplicateError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Duplicate found.");
				}
		};

	private:
		std::map<std::string, float>	_priceDB; //type a verifier
		std::map<std::string, int>		_maxDaysPerMonth;




};

#endif
