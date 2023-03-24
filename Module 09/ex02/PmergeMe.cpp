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

// bool	PmergeMe::customSort()
// {
// 	std::vector< std::pair<int, int> >::iterator it=_vector.begin();
// 	if ((*it).first == -1)
// 	{
// 		std::cout << "hello custom" << std::endl;
// 		std::swap(_vector.front(), _vector.back());
// 	}
// 	return ();
// }


void	PmergeMe::sortWithVector(int argc, char *argv[])
{
	int					num = argc - 1;
	int					tempura;
	std::vector<int>	result;

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
		result.push_back((*it).first);
	}

	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		int	i = result.size()/2;
		if ((*it).second < result[i])
		{
			while ((*it).second < result[i])
			{
				std::cout << "DEB WHILE " << (*it).second << " < " << result[i]<< std::endl;
				i--;
				std::cout << "MEANWHILE " << (*it).second << " < " << result[i]<< std::endl;
				if (((*it).second > _vector[i].first))
				{
					std::cout << "INSERT " << (*it).second << " != " <<  result[i] << std::endl;
					result.insert(result.begin() + (i + 1), (*it).second);
					continue;
				}
				std::cout << "FIN WHILE " << (*it).second << " < " << result[i]<< std::endl;
			}
		}
		else
		{
			std::cout << "ELSE " << (*it).second << std::endl;
			while ((*it).second > result[i])
			{
				if ((*it).second > result.back())
				{
					std::cout << result.back() << " back spotted ! " << (*it).second << std::endl;
					result.insert(result.end(), (*it).second);
					break;
				}
				std::cout << "ELSE DEB WHILE " << (*it).second << " > " << result[i]<< std::endl;
				i++;
				std::cout << "MEANWHILE " << (*it).second << " > " << result[i]<< std::endl;
				if (((*it).second < _vector[i].first))
				{
					std::cout << "INSERT " << (*it).second << " != " <<  result[i] << std::endl;
					result.insert(result.begin() + (i), (*it).second);
					continue;
				}
				std::cout << "FIN WHILE " << (*it).second << " > " << result[i]<< std::endl;
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////
	// Print DEBUG ONLY
	///////////////////////////////////////////////////////////////////////////
	for (std::vector<int>::iterator it=result.begin(); it != result.end(); it++)
	{
		std::cout << (*it) << " | ";
	}
	std::cout << std::endl;
	///////////////////////////////////////////////////////////////////////////


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
	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		std::cout << (*it).first << " " << (*it).second << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}
