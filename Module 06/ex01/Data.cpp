/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:28:58 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 14:12:51 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data():
	anInt(0),
	aChar('\0'),
	aFloat(0.0)
{

}

Data::Data(Data const &src)
{
	*this = src;
}

Data	&Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		anInt = rhs.anInt;
		aChar = rhs.aChar;
		aFloat = rhs.aFloat;
	}
	return (*this);
}

Data::~Data()
{

}

