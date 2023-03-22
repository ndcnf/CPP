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
	_set = rhs._set;
	_vector = rhs._vector;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}
