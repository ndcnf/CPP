#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_maxDaysPerMonth[1] = 31;
	_maxDaysPerMonth[2] = 29;
	_maxDaysPerMonth[3] = 31;
	_maxDaysPerMonth[4] = 30;
	_maxDaysPerMonth[5] = 31;
	_maxDaysPerMonth[6] = 30;
	_maxDaysPerMonth[7] = 31;
	_maxDaysPerMonth[8] = 31;
	_maxDaysPerMonth[9] = 30;
	_maxDaysPerMonth[10] = 31;
	_maxDaysPerMonth[11] = 30;
	_maxDaysPerMonth[12] = 31;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_priceDB = rhs._priceDB;
	_maxDaysPerMonth = rhs._maxDaysPerMonth;
	_year = rhs._year;
	_month = rhs._month;
	_day = rhs._day;
	_value = rhs._value;

	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

bool	BitcoinExchange::getFileContentDB(std::string file)
{
	std::ifstream	ifs(file);
	std::string		content;
	bool			dateOK = false;
	bool			titleOK = false;
	bool			first = true;

	if (ifs.is_open())
	{
		while (ifs.good())
		{
			std::getline(ifs, content);
			if (ifs.eof())
			{
				ifs.close();
				return (true);
			}

			if (first)
			{
				titleOK = checkTitle(content, file);
				first = false;
			}
			else
				dateOK = checkValidityDB(content);

			if (dateOK && titleOK)
				_priceDB[content.substr(0, 10)] = _value;
		}
	}
	// else
	// 	return (false);
		// throw (fileError());

	return (false);
}

bool	BitcoinExchange::getFileContentInput(std::string file)
{
	std::ifstream	ifs(file);
	std::string		content;
	bool			dateOK = false;
	bool			titleOK = false;
	bool			first = true;
	std::string		dateInput;

	if (ifs.is_open())
	{
		while (ifs.good())
		{
			std::getline(ifs, content);
			if (ifs.eof())
			{
				ifs.close();
				return (true);
			}

			if (first)
			{
				titleOK = checkTitle(content, file);
				first = false;
			}
			else
				dateOK = checkValidityInput(content);

			if (dateOK && titleOK)
			{
				dateInput = content.substr(0, 10);
				_priceInput[dateInput] = _value;

				std::map<std::string, float>::iterator	it = _priceDB.lower_bound(dateInput);
				if ((*it).first > dateInput)
				{
					it--;
					std::cout	<< (*it).first << " ==> "
								<< _value << " = ";
					// std::cout.precision(4);
					std::cout	<< ((*it).second * _value)
								<< " (" << dateInput << " not found)"
								<< std::endl;
				}
				else
					std::cout	<< (*it).first << " ==> "
								<< _value << " = "
								<< ((*it).second * _value)
								<< std::endl;
			}
		}
	}

	return (false);
}

bool	BitcoinExchange::checkTitle(std::string line, std::string fileName)
{
	if (fileName != "data.csv")
	{
		if (!line.find("date | value"))
			return (true);
	}
	else if (!line.find("date,exchange_rate"))
		return (true);
	return (false);
}

bool	BitcoinExchange::checkValidityDB(std::string line)
{
	if (line[10] != ',')
	{
		std::cout << "[Warning: bad input in database]" << std::endl;
		return (false);
	}

	_year = atoi(line.substr(0, 4).c_str());
	_month = atoi(line.substr(5, 2).c_str());
	_day = atoi(line.substr(8, 2).c_str());
	_value = atof(line.substr(11).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (_year < 1000 || _year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (_month == (*it).first)
			{
				if (_day <= (*it).second)
					return (true);
			}
		}
	}
	std::cout << "[Warning: bad date in database => " << _year << "-" << _month << "-" << _day << "]" << std::endl;
	return (false);
}

bool	BitcoinExchange::checkValidityInput(std::string line)
{
	if (line[11] != '|')
	{
		std::cout << "Error: bad input" << std::endl;
		return (false);
	}

	_year = atoi(line.substr(0, 4).c_str());
	_month = atoi(line.substr(5, 2).c_str());
	_day = atoi(line.substr(8, 2).c_str());

	if (!isdigit(line[13]))
	{
		std::cout << "Error: not a valid number." << std::endl;
		return (false);
	}

	_value = atof(line.substr(13).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (_year < 1000 || _year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (_month == (*it).first)
			{
				if (_day <= (*it).second)
					return (true);
			}
		}
		// if (_value < 0)
		// {
		// 	std::cout << "Error: not a positive number." << std::endl;
		// 	return (false);
		// }
		if (_value > 1000 || _value >= std::numeric_limits<int>::max())
		{
			std::cout << "Error: too large a number." << std::endl;
			return (false);
		}
		// if (_value >= std::numeric_limits<int>::max())
		// {
		// 	std::cout << "Error: too large a number." << std::endl;
		// 	return (false);
		// }



		std::cout << "Error: bad date input => " << _year << "-" << _month << "-" << _day << std::endl;
	}
	return (false);
}


// void	BitcoinExchange::printResult()
// {
// 	std::cout << "-- DB --" << std::endl;

// 	for (std::map<std::string, float>::iterator it = _priceDB.begin(); it != _priceDB.end(); it++)
// 	{
// 		std::cout << "_priceDB[" << it->first << "] = " << it->second << std::endl;
// 	}

// 	std::cout << "-- INPUT --" << std::endl;

// 	for (std::map<std::string, float>::iterator it = _priceInput.begin(); it != _priceInput.end(); it++)
// 	{
// 		std::cout << "_priceInput[" << it->first << "] = " << it->second << std::endl;
// 	}
// }
