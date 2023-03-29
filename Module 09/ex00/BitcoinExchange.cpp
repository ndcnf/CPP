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
				std::map<std::string, float>::iterator	it;
				// std::pair<std::map<std::string, float>::iterator, std::map<std::string, float>::iterator>	ret;

				// it = std::lower_bound(_priceDB.begin(), _priceDB.end());
				it = _priceDB.lower_bound(dateInput);
				// it = _priceInput.equal_range(dateInput);
				// ret = _priceInput.equal_range(dateInput);
				_priceInput.find(dateInput);
				std::cout << dateInput << "[" << it->first << "] : ";
				// std::cout << ret.first->first << " / " << ret.first->second << std::endl;
				// std::cout << ret.second->first << " | " << ret.second->second << std::endl;
				std::cout << std::endl;
				// for (std::map<std::string, float>::iterator it = _priceInput.begin(); it != _priceInput.end(); it++)
				// {
				// 	// dateInput
				// }
				// std::cout << "{INPUT VALUE} = " << _value << std::endl;

			}
		}
	}
	// else
	// 	return (false);

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
		std::cout << "Error: bad input in database" << std::endl;
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
	// + verifier jours (bonus: bisextiles)
	}
	std::cout << "Error: bad date in database => " << _year << "-" << _month << "-" << _day << std::endl;
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
	// + verifier jours (bonus: bisextiles)
		// if (_value < 0 && _value)




		std::cout << "Error: bad date input => " << _year << "-" << _month << "-" << _day << std::endl;
	}
	return (false);
}


void	BitcoinExchange::printResult()
{
	std::cout << "-- DB --" << std::endl;

	for (std::map<std::string, float>::iterator it = _priceDB.begin(); it != _priceDB.end(); it++)
	{
		std::cout << "_priceDB[" << it->first << "] = " << it->second << std::endl;
	}

	std::cout << "-- INPUT --" << std::endl;

	for (std::map<std::string, float>::iterator it = _priceInput.begin(); it != _priceInput.end(); it++)
	{
		std::cout << "_priceInput[" << it->first << "] = " << it->second << std::endl;
	}
}
