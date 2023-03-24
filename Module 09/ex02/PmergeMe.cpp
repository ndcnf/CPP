#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	_list = rhs._list;
	_vector = rhs._vector;
	return (*this);
}

void	PmergeMe::duplicateDetector(int argc, char *argv[])
{
	std::set<int>	dd;

	for (int i = 1; i < argc; i++)
		dd.insert(atoi(argv[i]));
	if (dd.size() != static_cast<unsigned int>(argc - 1))
	{
		std::cout << "size of std::set (no duplicate) : " << dd.size() << std::endl;
		std::cout << "number of integers given        : " << argc-1 << std::endl;
		throw(PmergeMe::DuplicateError());
	}
}

void	PmergeMe::sortWithVector(int argc, char *argv[])
{
	int					num = argc - 1;
	int					tempura;

	//TIMER GO
	for (int i = 1; i < argc; i++)
	{
		if (!(num % 2))
		{
			if (i % 2)
				_vector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+1])));
		}
		else
		{
			if (i % 2)
			{
				if (i == num)
					_vector.push_back(std::make_pair(-1, atoi(argv[i])));
				else
					_vector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+1])));
			}
		}
	}

	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			tempura = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tempura;
		}
	}

	std::sort(_vector.begin(), _vector.end());

	std::vector< std::pair<int, int> >::iterator it=_vector.begin();
	if ((*it).first == -1)
	{
		_vector.insert(_vector.end(), _vector.front());
		_vector.erase(_vector.begin());
	}

	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		if ((*it).first == -1)
			continue;
		_result.push_back((*it).first);
	}

	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		int	i = _result.size()/2;
		if ((*it).second < _result[i])
		{
			while ((*it).second < _result[i])
			{
				i--;
				if (((*it).second > _result[i]))
				{
					_result.insert(_result.begin() + (i + 1), (*it).second);
					continue;
				}
			}
		}
		else
		{
			while ((*it).second > _result[i])
			{
				if ((*it).second > _result.back())
				{
					_result.insert(_result.end(), (*it).second);
					continue;
				}
				i++;
				if (((*it).second < _result[i]))
				{
					_result.insert(_result.begin() + i, (*it).second);
					continue;
				}
			}
		}
	}

	//TIMER STOP
}

void	PmergeMe::sortWithList(int argc, char *argv[])
{
	//TIMER GO
	for (int i = 1; i < argc; i++)
	{
		_list.push_back(atoi(argv[i]));
	}





	//TIMER STOP
}


void	PmergeMe::printResultVector()
{
	for (std::vector<int>::iterator it=_result.begin(); it != _result.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
	std::cout << "_result.size(): " << _result.size() << std::endl;
}

PmergeMe::~PmergeMe()
{

}
