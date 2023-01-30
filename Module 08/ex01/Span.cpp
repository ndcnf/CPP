/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:58 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/27 14:27:17 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): _n(n)
{
	if (n <= 1)
		throw (Span::invalidSize);
}

Span(Span const &src)
{
	*this = src;
}

Span &operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_data = rhs._data;
	}
	return (*this);
}

Span::Span()
{}

Span::~Span()
{}


void	Span::addNumber(unsigned int i)
{
	//verification si correct. Mais verifier avant si le programme s'arrete directement.
	if (i < 0)
		throw(Span::invalidData);
	_data.push_back(i);
}

unsigned int	Span::longestSpan()
{
	if (_n < 2)
		throw (invalidSize);
	std::vector<unsigned int>::iterator	lowestN;
	std::vector<unsigned int>::iterator	highestN;

	highestN = std::max_element(it.begin(), it.end());
	lowestN = std::min_element(it.begin(), it.end());

	return (highestN - lowestN);
}

unsigned int	Span::shortestSpan()
{
	if (_n < 2)
		throw (invalidSize);
	
	int	lowestDelta = _data[0] - _data[1];
	std::vector<unsigned int>::iterator it;
	for (it=_data.begin(); it != _data.end(); it++)
	{
		while ((*it + 1) != _data.end())
		{
			if (lowestDelta > (*it - *it + 1))
				lowestDelta = (*it - *it + 1);
		}
	}
	return (lowestDelta);
}

