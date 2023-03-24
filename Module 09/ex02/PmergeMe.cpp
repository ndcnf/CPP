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
	int	num = argc - 1;
	int	tempura;
	//TIMER GO
	for (int i = 1; i < argc; i++)
	// for (int i = num - 1; i >= 0; i--)
	{
		if (!(num % 2))
		{
			if (i % 2)
			{
				_vector.push_back(std::make_pair(atoi(argv[i]), atoi(argv[i+1])));
			}
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
			// else
			// {

			// }
		}





		// if (i % 2)
		// {
		// 	std::cout << "On passe" << std::endl;
		// }
		// else if ((num % 2))
		// {
		// 	// _vector.push_back(std::make_pair(-1, atoi(argv[i])));
		// 	_vector.push_back(std::make_pair(atoi(argv[i-1]), atoi(argv[i])));
		// 	std::cout << "VRAI" << std::endl;
		// }
		// else
		// {
		// 	_vector.push_back(std::make_pair(-1, atoi(argv[i])));

		// 	std::cout << "FAUX" << std::endl;
		// }
		// std::cout << _vector[i].first << " & " << _vector[i].second << std::endl;
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

	// if (num % 2)
	// {

	// }
	// else
	// {
	// 	for (int i = num - 1; i == 0; i--)
	// 	{
	// 		if (!(i % 2))
	// 		{
	// 			if (_vector[i] > _vector[i+2])
	// 		}
	// 	}
	// }




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
