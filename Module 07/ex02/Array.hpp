/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:03:04 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/26 15:46:58 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
	public:
		Array():
			_nbr(0)
		{
			_tab = NULL;
			_tab = new T[_nbr];
		}

		Array(unsigned int n):
			_nbr(n)
		{
			_tab = new T[_nbr];
		}

		Array(Array const & src)
		{
			_tab = NULL;
			*this = src;
		}

		Array &operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				if (_tab)
					delete [] _tab;
				_nbr = rhs._nbr;
				_tab = new T[_nbr];

				for (unsigned int i= 0; i < _nbr; i++)
					_tab[i] = rhs._tab[i];
			}
			return (*this);
		}

		unsigned int	size()
		{
			return (_nbr);
		}

		unsigned int	getNbr() const
		{
			return (_nbr);
		}

		T &operator[](unsigned int i)
		{
			if (_nbr <= i || i < 0)
				throw(std::out_of_range("out of range"));
			return (_tab[i]);
		}

		~Array()
		{
			// std::cout << "destructor called" << std::endl;
			if (_tab)
				delete [] _tab;
		}

	private:
		T				*_tab;
		unsigned int	_nbr;
};

#endif
