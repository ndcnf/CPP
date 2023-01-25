/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:27:14 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/25 12:30:49 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
T	const & min(T const &x, T const &y)
{
	if (x < y)
		return (x);
	return (y);
}

template< typename T >
T	const & max(T const &x, T const &y)
{
	if (x >= y)
		return (x);
	return (y);
}

template< typename T >
void	swap(T &x, T &y)
{
	T	tempura = x;

	x = y;
	y = tempura;
}

#endif
