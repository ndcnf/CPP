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
	_sortedList = rhs._sortedList;
	_sortedVector = rhs._sortedVector;

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

void	PmergeMe::pairingVector(int num, char *argv[])
{
	for (int i = 1; i < (num +1); i++)
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
}

void	PmergeMe::swapPairVector()
{
	int	tempura;

	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			tempura = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tempura;
		}
	}
}

void	PmergeMe::copyVector()
{
	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		if ((*it).first == -1)
			continue;
		_sortedVector.push_back((*it).first);
	}
}

void	PmergeMe::sortBinarySearchVector()
{
	for (std::vector< std::pair<int, int> >::iterator it=_vector.begin(); it != _vector.end(); it++)
	{
		int	i = _sortedVector.size()/2;
		if ((*it).second < _sortedVector[i])
		{
			while ((*it).second < _sortedVector[i])
			{
				i--;
				if (((*it).second > _sortedVector[i]))
				{
					_sortedVector.insert(_sortedVector.begin() + (i + 1), (*it).second);
					continue;
				}
			}
		}
		else
		{
			while ((*it).second > _sortedVector[i])
			{
				if ((*it).second > _sortedVector.back())
				{
					_sortedVector.insert(_sortedVector.end(), (*it).second);
					continue;
				}
				i++;
				if (((*it).second < _sortedVector[i]))
				{
					_sortedVector.insert(_sortedVector.begin() + i, (*it).second);
					continue;
				}
			}
		}
	}
}


void	PmergeMe::sortWithVector(int argc, char *argv[])
{
	//TIMER GO
	pairingVector(argc -1, argv);
	swapPairVector();

	std::sort(_vector.begin(), _vector.end());
	std::vector< std::pair<int, int> >::iterator it=_vector.begin();
	if ((*it).first == -1)
	{
		_vector.insert(_vector.end(), _vector.front());
		_vector.erase(_vector.begin());
	}

	copyVector();
	sortBinarySearchVector();

	//TIMER STOP
}

void	PmergeMe::pairingList(int num, char *argv[])
{
	for (int i = 1; i < (num +1); i++)
	{
		if (!(num % 2))
		{
			if (i % 2)
				_list.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+1])));
		}
		else
		{
			if (i % 2)
			{
				if (i == num)
					_list.push_back(std::make_pair(-1, atoi(argv[i])));
				else
					_list.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+1])));
			}
		}
	}
}

void	PmergeMe::swapPairList()
{
	int	tempura;

	for (std::list< std::pair<int, int> >::iterator it=_list.begin(); it != _list.end(); it++)
	{
		if ((*it).first > (*it).second)
		{
			tempura = (*it).first;
			(*it).first = (*it).second;
			(*it).second = tempura;
		}
	}
}

void	PmergeMe::copyList()
{
	for (std::list< std::pair<int, int> >::iterator it=_list.begin(); it != _list.end(); it++)
	{
		if ((*it).first == -1)
			continue;
		_sortedList.push_back((*it).first);
	}

	////////////////////////////////////////////////////////////////////////////
	// Afficher la liste pour DEBUG
	////////////////////////////////////////////////////////////////////////////
	std::cout << "DEBUG [";
	for (std::list< std::pair<int, int> >::iterator it=_list.begin(); it != _list.end(); it++)
	{
		std::cout << (*it).first << " " << (*it).second << " ";
	}
	std::cout << "]" << std::endl;
}

// void	PmergeMe::sortBinarySearchList()
// {

	////////////////////////////////////////////////////////////////////////////
	// Une liste n'est pas parcourable via [] semble-t-il. Il faudra naviguer
	// autrement
	////////////////////////////////////////////////////////////////////////////

	// for (std::list< std::pair<int, int> >::iterator it=_list.begin(); it != _list.end(); it++)
	// {
	// 	int	i = _sortedList.size()/2;
	// 	if ((*it).second < _sortedList[i])
	// 	{
	// 		while ((*it).second < _sortedList[i])
	// 		{
	// 			i--;
	// 			if (((*it).second > _sortedList[i]))
	// 			{
	// 				_sortedList.insert(_sortedList.begin() + (i + 1), (*it).second);
	// 				continue;
	// 			}
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while ((*it).second > _sortedList[i])
	// 		{
	// 			if ((*it).second > _sortedList.back())
	// 			{
	// 				_sortedList.insert(_sortedList.end(), (*it).second);
	// 				continue;
	// 			}
	// 			i++;
	// 			if (((*it).second < _sortedList[i]))
	// 			{
	// 				_sortedList.insert(_sortedList.begin() + i, (*it).second);
	// 				continue;
	// 			}
	// 		}
	// 	}
	// }
// }


void	PmergeMe::sortWithList(int argc, char *argv[])
{
	//TIMER GO
	pairingList(argc -1, argv);
	swapPairList();

	// std::sort(_list.begin(), _list.end()); // ------------------------------------------------ LIGNE PROBLEMATIQUE
	std::list< std::pair<int, int> >::iterator it=_list.begin();
	if ((*it).first == -1)
	{
		_list.insert(_list.end(), _list.front());
		_list.erase(_list.begin());
	}

	copyList();
	// sortBinarySearchList();





	//TIMER STOP
}


void	PmergeMe::printResultVector()
{
	for (std::vector<int>::iterator it=_sortedVector.begin(); it != _sortedVector.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;

	////////////////////////////////////////////////////////////////////////////
	// Afficher la liste pour DEBUG
	////////////////////////////////////////////////////////////////////////////
	// for (std::list<int>::iterator it=_sortedList.begin(); it != _sortedList.end(); it++)
	// {
	// 	std::cout << (*it) << " ";
	// }
	// std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}
