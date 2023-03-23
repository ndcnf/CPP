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

void	PmergeMe::pairUp(int i)
{
	(void)i;
	// _vector.push_back(i);
}

void	PmergeMe::sortWithVector(int argc, char *argv[])
{
	int	num = argc - 1;
	int	tempura;
	//TIMER GO
	for (int i = 1; i < argc; i++)
	{
		_vector.push_back(atoi(argv[i]));
	}

	for (int i = 0; i < num; i++)
	{
		if (i % 2)
		{
			if (_vector[i] < _vector[i-1])
			{
				tempura = _vector[i];
				_vector[i] = _vector[i-1];
				_vector[i-1] = tempura;
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
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{

}
