/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:58 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/31 13:56:09 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _n(n)
{
	if (n <= 1)
		throw (Span::invalidSize());

}

Span::Span(Span const &src)
{
	*this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_data = rhs._data;
	}
	return (*this);
}

Span::Span(): _n(0)
{}

Span::~Span()
{}

void	Span::addNumber(int i)
{
	if (i < 0)
		throw(Span::invalidData());
	_data.push_back(i);
}

unsigned int	Span::longestSpan()
{
	if (_n < 2)
		throw (invalidSize());

	std::vector<unsigned int>::iterator	lowestN;
	std::vector<unsigned int>::iterator	highestN;

	highestN = std::max_element(_data.begin(), _data.end());
	lowestN = std::min_element(_data.begin(), _data.end());

	return (*highestN - *lowestN);
}

unsigned int	Span::shortestSpan()
{
	if (_n < 2)
		throw (invalidSize());

	std::sort(_data.begin(), _data.end());
	unsigned int	lowestDelta = _data[1] - _data[0];

	std::vector<unsigned int>::iterator it;
	for (it=_data.begin(); it != _data.end(); it++)
	{
		if (it + 1 != _data.end())
		{
			if (lowestDelta > *(it + 1) - *it)
				lowestDelta = *(it + 1) - *it;
		}
	}
	return (lowestDelta);
}

void	Span::generateTab()
{
	srand(time(NULL));
	for (unsigned int i=0; i < _n; i++)
		_data.push_back(rand());
}
