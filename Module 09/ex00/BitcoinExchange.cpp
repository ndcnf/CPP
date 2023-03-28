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

std::string	BitcoinExchange::getFileContent(std::string file)
{
	std::ifstream	ifs(file);
	std::string		content;
	bool			dateOK;

	if (ifs.is_open())
	{
		while (ifs.good())
		{
			std::getline(ifs, content);
			dateOK = checkDateValidity(content);
			if (dateOK)
				std::cout << "YES!" << std::endl;
			// std::cout << content << std::endl;
		// char c = ifs.get();
		// while (ifs.good())
		// {
		// 	content += c;
		// 	c = ifs.get();
		}
	}
	else
	{
		std::cout	<< "Error: Opening file impossible"
					<< std::endl;
	}
	ifs.close();
	return (content);
}

bool	BitcoinExchange::checkDateValidity(std::string line)
{
	std::cout << "[" << line << "]" << std::endl;
	if (!line.rfind("date"))
	{
		return (true);
	}
	return (false);


	


	// for (std::map<std::string, int>::iterator it=_maxDaysPerMonth.begin(); it != _maxDaysPerMonth.end(); it++)
	// {
	// 	std::cout << (*it).first << " - " << (*it).second << std::endl;
	// }
}
