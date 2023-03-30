#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <algorithm>
# include <stdexcept>
# include <fstream>
# include <limits>
# include <map>

# define ERROR "Error: "
# define WARNING "[ Warning: "
# define ERR_BAD_DATE_IN "bad date input."
# define ERR_NUM_TOO_LRG "too large a number."
# define ERR_INVALID_NUM "not a valid number."
# define ERR_NEGATIVE_NUM "not a positive number."
# define ERR_BAD_IN "bad input."
# define ERR_TOO_EARLY "Bitcoin wasn't even invented yet."
# define ERR_BAD_IN_DB "bad input in database. ]"
# define ERR_BAD_DATE_DB "bad date in database. ]"
# define DB_FILE "data.csv"
# define DB_HEADER "date,exchange_rate"
# define IN_HEADER "date | value"

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		bool	getFileContentDB(std::string file);
		bool	getFileContentInput(std::string file);
		bool	checkValidityDB(std::string line);
		bool	checkValidityInput(std::string line);
		bool	checkTitle(std::string line, std::string fileName);

		class fileError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Opening file impossible.");
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

	private:
		std::map<std::string, float>	_priceDB;
		std::map<int, int>				_maxDaysPerMonth;
		int								_year;
		int								_month;
		int								_day;
		float							_value;
};

#endif
