/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:40:34 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 14:03:52 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/********************************************
* CONSTRUCTORS & DESTRUCTORS				*
********************************************/
Fixed::Fixed() : _value(0)
{
	// std::cout	<< "Default constructor called"
	// 			<< std::endl;
}

// NOTE - (i << _bitNb) is 256. It is not supported by float, only int here
Fixed::Fixed(int i) : _value(i << _bitsNb)
{
	// std::cout	<< "Int constructor called"
	// 			<< std::endl;
}

Fixed::Fixed(float f) : _value(roundf(f * (1 << _bitsNb)))
{
	// std::cout	<< "Float constructor called"
	// 			<< std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout	<< "Copy constructor called"
	// 			<< std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	// std::cout	<< "Destructor called"
	// 			<< std::endl;
}

/********************************************
* FUNCTIONS									*
********************************************/
int				Fixed::getRawBits(void) const
{
	return this->_value;
}

void			Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float			Fixed::toFloat() const
{
	return this->_value / (float)(1 << _bitsNb);
}

int				Fixed::toInt() const
{
	return this->_value >> _bitsNb;
}

const Fixed &	Fixed::min(const Fixed & n1, const Fixed & n2)
{
	if (n1 >= n2)
		return (n2);
	return (n1);
}

const Fixed &	Fixed::max(const Fixed & n1, const Fixed & n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

Fixed &		min(Fixed & n1, Fixed & n2)
{
	if (n1 >= n2)
		return (n2);
	return (n1);
}

Fixed &		max(Fixed & n1, Fixed & n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}


/********************************************
* OPERATORS									*
********************************************/
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	// std::cout	<< "Copy assignment operator called"
	// 			<< std::endl;
	if (this != &rhs)
		this->_value = rhs._value;
	return *this;
}


Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tempura(*this);
	++(*this);
	return (tempura);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tempura(*this);
	--(*this);
	return (tempura);
}

Fixed &	Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed &	Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}
