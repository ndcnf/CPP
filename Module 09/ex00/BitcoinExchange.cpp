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
				return (true);

			if (first)
			{
				titleOK = checkTitle(content, file);
				first = false;
			}
			else
				dateOK = checkValidityDB(content);

			if (dateOK && titleOK)
			{
				_priceDB[content.substr(0, 10)] = _value;
				// _priceDB.insert(std::pair<std::string,float>(file.substr(0, 4), _value));
			}
		}
	}
	else
		throw (fileError());

	ifs.close();

	// if (dateOK && titleOK)
	// 	return (true);
	return (false);
}

bool	BitcoinExchange::getFileContentInput(std::string file)
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
				return (true);

			if (first)
			{
				titleOK = checkTitle(content, file);
				first = false;
			}
			else
				dateOK = checkValidityInput(content);
		}
	}
	else
		return (false);

	ifs.close();

	if (dateOK && titleOK)
		return (true);
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
	// int	year = atoi(line.substr(0, 4).c_str());
	// int	month = atoi(line.substr(5, 2).c_str());
	// int	day = atoi(line.substr(8, 2).c_str());

	_year = atoi(line.substr(0, 4).c_str());
	_month = atoi(line.substr(5, 2).c_str());
	_day = atoi(line.substr(8, 2).c_str());
	_value = atof(line.substr(11).c_str());

	// std::cout << _value << std::endl;
	if (line[4] == '-' && line[7] == '-')
	{
		if (_year < 1000 || _year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (_month == (*it).first)
			{
				if (_day <= (*it).second)
				{

					return (true);
				}
				else
				{
					std::cout << "Error: bad input => " << _year << "-" << _month << "-" << _day << std::endl;
					return (false);
				}
			}
		}
	// + verifier jours (bonus: bisextiles)
	}
	return (false);
}

bool	BitcoinExchange::checkValidityInput(std::string line)
{
	// int	year = atoi(line.substr(0, 4).c_str());
	// int	month = atoi(line.substr(5, 2).c_str());
	// int	day = atoi(line.substr(8, 2).c_str());

	_year = atoi(line.substr(0, 4).c_str());
	_month = atoi(line.substr(5, 2).c_str());
	_day = atoi(line.substr(8, 2).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (_year < 1000 || _year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (_month == (*it).first)
			{
				if (_day <= (*it).second)
				{
					// std::cout << (*it).first << " => " << (*it).second << " = JUSTE DATE OK" << std::endl;
					// IMPRIMER LE RESULTAT ICI
					return (true);
				}
				else
				{
					std::cout << "Error: bad input => " << _year << "-" << _month << "-" << _day << std::endl;
					return (false);
				}
			}
		}
	// + verifier jours (bonus: bisextiles)
	}
	return (false);

	// for (std::map<std::string, int>::iterator it=_maxDaysPerMonth.begin(); it != _maxDaysPerMonth.end(); it++)
	// {
	// 	std::cout << (*it).first << " - " << (*it).second << std::endl;
	// }
}


void	BitcoinExchange::printResult()
{
	for (std::map<std::string, float>::iterator it = _priceDB.begin(); it != _priceDB.end(); it++)
	{
		std::cout << "_priceDB[" << it->first << "] = " << it->second << std::endl;
	}
}
