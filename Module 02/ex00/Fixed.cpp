/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:06:47 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/29 13:50:25 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Alternative : Fixed::Fixed() : _value(0)
Fixed::Fixed()
{
	std::cout	<< "Default constructor called"
				<< std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout	<< "Destructor called"
				<< std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout	<< "Copy constructor called"
				<< std::endl;
	*this = src;
}

Fixed &Fixed::operator=(Fixed const & rhs)
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return *this;
}

int			Fixed::getRawBits(void) const
{
	std::cout	<< "getRawBits member function called"
				<< std::endl;
	return this->_value;
}

void		Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

