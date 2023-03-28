#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	_maxDaysPerMonth.insert(std::pair<std::string,int>("01", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("02", 29));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("03", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("04", 30));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("05", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("06", 30));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("07", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("08", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("09", 30));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("10", 31));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("11", 30));
	_maxDaysPerMonth.insert(std::pair<std::string,int>("12", 31));
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
	int	year = atoi(line.substr(0, 4).c_str());

	if (line[4] == '-' && line[7] == '-')
	{
		if (year >= 1000 && year <= 3000)
			std::cout << year << " OK" << std::endl;
	// + verifier annee

	// + verfier mois

	// + verifier jours (bonus: bisextiles)
		return (true);
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
