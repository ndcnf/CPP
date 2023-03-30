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

		class dateError: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: bad input.");
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
		std::map<std::string, float>	_priceInput;
		std::map<int, int>				_maxDaysPerMonth;
		int								_year;
		int								_month;
		int								_day;
		float							_value;




};

#endif
