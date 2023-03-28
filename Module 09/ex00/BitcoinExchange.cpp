#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("01", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("02", 29));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("03", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("04", 30));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("05", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("06", 30));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("07", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("08", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("09", 30));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("10", 31));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("11", 30));
	// _maxDaysPerMonth.insert(std::pair<std::string,int>("12", 31));

	_maxDaysPerMonth.insert(std::pair<int,int>(1, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(2, 29));
	_maxDaysPerMonth.insert(std::pair<int,int>(3, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(4, 30));
	_maxDaysPerMonth.insert(std::pair<int,int>(5, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(6, 30));
	_maxDaysPerMonth.insert(std::pair<int,int>(7, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(8, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(9, 30));
	_maxDaysPerMonth.insert(std::pair<int,int>(10, 31));
	_maxDaysPerMonth.insert(std::pair<int,int>(11, 30));
	_maxDaysPerMonth.insert(std::pair<int,int>(12, 31));
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	_priceDB = rhs._priceDB;
	_maxDaysPerMonth = rhs._maxDaysPerMonth;

	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

bool	BitcoinExchange::getFileContent(std::string file)
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
			if (first)
			{
				titleOK = checkTitle(content, file);
				first = false;
			}
			else
				dateOK = checkDateValidity(content);
		}
	}
	else
		throw (fileError());

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

bool	BitcoinExchange::checkDateValidity(std::string line)
{
	// int	year = atoi(line.substr(0, 4).c_str());
	// int	month = atoi(line.substr(5, 2).c_str());
	// int	day = atoi(line.substr(8, 2).c_str());

	_year = atoi(line.substr(0, 4).c_str());
	_month = atoi(line.substr(5, 2).c_str());
	_day = atoi(line.substr(8, 2).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (year < 1000 || year > 3000)
			return (false);

		for (std::map<int, int>::iterator it=_maxDaysPerMonth.begin(); it !=_maxDaysPerMonth.end(); it++)
		{
			if (month == (*it).first)
			{
				if (day <= (*it).second)
				{
					return (true);
				}
				else
				{
					std::cout << "Error: bad imput => " << year << "-" << month << "-" << day << std::endl;
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

}
