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



void	BitcoinExchange::checkDateValidity()
{
	for (std::map<std::string, int>::iterator it=_maxDaysPerMonth.begin(); it != _maxDaysPerMonth.end(); it++)
	{
		std::cout << (*it).first << " - " << (*it).second << std::endl;
	}
}
