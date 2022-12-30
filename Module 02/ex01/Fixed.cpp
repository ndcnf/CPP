/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:34 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/30 12:22:09 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout	<< "Default constructor called"
				<< std::endl;
	this->_value = 0;
}

// NOTE - (i << _bitNb) is 256. It is not supported by float, only int here
Fixed::Fixed(int i) : _value(i << _bitsNb)
{
	std::cout	<< "Int constructor called"
				<< std::endl;
}

Fixed::Fixed(float f) : _value(roundf(f * (1 << _bitsNb)))
{
	std::cout	<< "Float constructor called"
				<< std::endl;
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

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	std::cout	<< "Copy assignment operator called"
				<< std::endl;
	if (this != &rhs)
		this->_value = rhs._value;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

float	Fixed::toFloat() const
{
	// float pow = (1 << _bitsNb);
	return this->_value / (float)(1 << _bitsNb);
}

int		Fixed::toInt() const
{
	return this->_value >> _bitsNb;
}
