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
	std::string		dateDB;

	if (ifs.is_open())
	{
		while (ifs.good())
		{
			content.clear();
			std::getline(ifs, content);
			if (ifs.eof())
			{
				ifs.close();
				return (true);
			}

			if (first)
			{
				titleOK = checkTitle(content, file);
				if (!titleOK)
					throw (formatError());
				first = false;
			}
			else
				dateOK = checkValidityDB(content);

			if (dateOK && titleOK)
			{
				dateDB = content.substr(0, 10);
				_priceDB[dateDB] = _value;
			}
		}
	}

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
			content.clear();
			std::getline(ifs, content);
			if (ifs.eof())
			{
				ifs.close();
				return (true);
			}

			if (first)
			{
				titleOK = checkTitle(content, file);
				if (!titleOK)
					throw (formatError());
				first = false;
			}
			else
				dateOK = checkValidityInput(content);

			if (dateOK && titleOK)
			{
				dateInput = content.substr(0, 10);
				std::map<std::string, float>::iterator	it = _priceDB.lower_bound(dateInput);

				if ((*it).first > dateInput || (it) == _priceDB.end())
				{
					if ((it) != _priceDB.begin())
					{
						it--;
						std::cout	<< dateInput << " ==> "
									<< std::setw(10) << std::left << _value << " = "
									<< std::setw(15) << std::right << ((*it).second * _value)
									<< std::setw(15) << " (based on " << (*it).first << ")"
									<< std::endl;
					}
					else
						std::cout << ERROR ERR_TOO_EARLY << std::endl;
				}
				else
					std::cout	<< dateInput << " ==> "
								<< std::setw(10) << std::left << _value << " = "
								<< std::setw(15) << std::right << ((*it).second * _value)
								<< std::endl;
			}
		}
	}

	return (false);
}

bool	BitcoinExchange::checkTitle(std::string line, std::string fileName)
{
	if (fileName != DB_FILE)
	{
		if (!line.find(IN_HEADER))
			return (true);
	}
	else if (!line.find(DB_HEADER))
		return (true);
	return (false);
}

bool	BitcoinExchange::checkValidityDB(std::string line)
{
	size_t	found = line.find(",");

	if (found == std::string::npos || line.size() < 12)
	{
		std::cout << WARNING ERR_BAD_IN_DB " ( ==> " << line << ")" << std::endl;
		return (false);
	}

	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 2).c_str());
	int	day = atoi(line.substr(8, 2).c_str());

	_value = atof(line.substr(11).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (year < 1000 || year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (month == (*it).first)
			{
				if (day <= (*it).second)
					return (true);
			}
		}
		std::cout << WARNING ERR_BAD_DATE_DB " => " << year << "-" << month << "-" << day << "]" << std::endl;
	}
	return (false);
}

bool	BitcoinExchange::checkValidityInput(std::string line)
{
	size_t	found = line.find(" | ");

	if (found == std::string::npos || line.size() < 14)
	{
		std::cout << ERROR ERR_BAD_IN " ( ==> " << line << ")" << std::endl;
		return (false);
	}

	int	year = atoi(line.substr(0, 4).c_str());
	int	month = atoi(line.substr(5, 2).c_str());
	int	day = atoi(line.substr(8, 2).c_str());

	if (!isdigit(line[13]))
	{
		if (line[13] == '-')
			std::cout << ERROR ERR_NEGATIVE_NUM << std::endl;
		else
			std::cout << ERROR ERR_INVALID_NUM << std::endl;

		return (false);
	}

	_value = atof(line.substr(13).c_str());

	if (_value > 1000)
	{
		std::cout << ERROR ERR_NUM_TOO_LRG << std::endl;
		return (false);
	}

	if (line[4] == '-' && line[7] == '-')
	{
		if (year < 1000 || year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (month == (*it).first)
			{
				if (day <= (*it).second)
					return (true);
			}
		}
		std::cout << ERROR ERR_BAD_DATE_IN " => " << year << "-" << month << "-" << day << std::endl;
	}
	return (false);
}
