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

// std::string	BitcoinExchange::getFileContent(std::string file)
void	BitcoinExchange::getFileContent(std::string file)
{
	std::ifstream	ifs(file);
	std::string		content;
	bool			dateOK;
	bool			titleOK;

	if (ifs.is_open())
	{
		while (ifs.good())
		{
			std::getline(ifs, content);
			// if (file != "data.csv")
			titleOK = checkTitle(content, file);
			dateOK = checkDateValidity(content);
			std::cout << titleOK << std::endl;
			if (dateOK)
				std::cout << "YES!" << std::endl;
			// std::cout << content << std::endl;
		}
	}
	else
		throw (fileError());

	ifs.close();
	// return (content);
}
bool	BitcoinExchange::checkTitle(std::string line, std::string fileName)
{
	std::cout << "[" << line << "]" << std::endl;
	if (fileName != "data.csv")
	{
		if (!line.find("date | value"))
			return (true);
	}

	if (!line.find("date,exchange_rate"))
		return (true);

	return (false);
}

bool	BitcoinExchange::checkDateValidity(std::string line)
{
	if (line[4] == '-' && line[7] == '-' && line[11] == '|')
		std::cout << "OK" << std::endl;



	return (false);

	// for (std::map<std::string, int>::iterator it=_maxDaysPerMonth.begin(); it != _maxDaysPerMonth.end(); it++)
	// {
	// 	std::cout << (*it).first << " - " << (*it).second << std::endl;
	// }
}

void	BitcoinExchange::printResult()
{
	
}