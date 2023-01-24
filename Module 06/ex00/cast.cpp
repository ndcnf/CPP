/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:32 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 10:36:27 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

cast::cast(std::string conv):
		_param(conv),
		_char('0'),
		_int(0),
		_float(0.0f),
		_double(0.0),
		_isChar(false),
		_isInt(false),
		_isFloat(false),
		_isDouble(false),
		_hasPoint(false),
		_hasSign(false),
		_hasF(false),
		_isNanInf(false)
{
	// std::cout	<< "Constructor called" << std::endl;
}

cast::cast(cast const & src)
{
	*this = src;
}

cast	&cast::operator=(cast const & rhs)
{
	if(this != &rhs)
	{
		_char = rhs._char;
		_int = rhs._int;
		_double = rhs._double;
		_float = rhs._float;
		_hasPoint = rhs._hasPoint;
		_hasSign = rhs._hasSign;
		_hasF = rhs._hasF;
		_isChar = rhs._isChar;
		_isDouble = rhs._isDouble;
		_isFloat = rhs._isFloat;
		_isInt = rhs._isInt;
		_isNanInf = rhs._isNanInf;
	}
	return (*this);
}

void	cast::exception(std::string src)
{
	_isNanInf = true;
	if (src == "nanf" || src == "-inff" || src == "+inff")
		_isFloat = true;
	else
		_isDouble = true;
}

void	cast::detection(std::string src)
{
	std::size_t		pos;

	// pos = src.find_first_not_of("0123456789-");

	pos = src.find_first_of("0123456789-");
	// if (src == "nan" || src == "inff" || src == "nanf" || src == "inf")
	// 	exception(src);
	if (pos != std::string::npos)
	{
		pos = src.find("-");
		if (pos != std::string::npos)
			_hasSign = true;

		pos = src.find(".");
		if (pos != std::string::npos)
		{
			_hasPoint = true;
			pos = src.find("f");
			if (pos != std::string::npos)
			{
				_hasF = true;
				_isFloat = true;
			}
			else
				_isDouble = true;
		}
		else if (src.length() >= 1)
			_isInt = true;
		else
		{
			_isChar = true;
			_hasSign = false;
		}
	}
	else if (src.length() == 1)
		_isChar = true;
	else if (src == "nan" || src == "inff" || src == "nanf" || src == "inf")
		exception(src);
	else
		std::cout << "Not a valid data here." << std::endl;

	std::cout << std::endl;
	std::cout << "--- BOOL TESTS ---" << std::endl;
	std::cout << "point:  " << _hasPoint << std::endl;
	std::cout << "sign:   " << _hasSign << std::endl;
	std::cout << "f:      " << _hasF << std::endl;
	std::cout << "isChar: " << _isChar <<std::endl;
	std::cout << "isInt:  " << _isInt <<std::endl;
	std::cout << "ifFlt:  " << _isFloat <<std::endl;
	std::cout << "isDble: " << _isDouble <<std::endl;
	std::cout << "isNanIn:" << _isDouble <<std::endl;
	std::cout << std::endl;
}

void	cast::selection(std::string src)
{
	if (_isChar)
		SrcChar(src);
	else if (_isInt)
		SrcInt(src);
	else if (_isFloat)
		SrcFloat(src);
	else if (_isDouble)
		SrcDouble(src);
	else
		std::cout << "Invalid data." << std::endl;
}

void	cast::printChar()
{
	int	i = static_cast<int>(_char);

	std::cout	<< "char:   ";
	if (i < 127 && i >= 32)
		std::cout	<< "'" << _char << "'" << std::endl;
	else if (_isNanInf)
		std::cout << "impossible" << std::endl;
	else
		std::cout	<< "not displayable" << std::endl;
}

void	cast::printInt()
{
	std::cout	<< "int:    ";
	if (_isNanInf)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
}

void	cast::printFloat()
{
	std::cout	<< "float:  ";
	std::cout << std::fixed << std::setprecision(1) << _float << "f" << std::endl;
}

void	cast::printDouble()
{
	std::cout	<< "double: ";
	std::cout << std::fixed << std::setprecision(1) << _double << std::endl;
}


void	cast::SrcChar(std::string src)
{
	char c = src[0];

	_char = static_cast<char>(c);
	_int = static_cast<int>(c);
	_float = static_cast<float>(c);
	_double = static_cast<double>(c);
}

void	cast::SrcInt(std::string src)
{
	int	i = stoi(src);

	_char = static_cast<char>(i);
	_int = static_cast<int>(i);
	_float = static_cast<float>(i);
	_double = static_cast<double>(i);
}

void	cast::SrcFloat(std::string src)
{
	float	f = stof(src);

	_char = static_cast<char>(f);
	_int = static_cast<int>(f);
	_float = static_cast<float>(f);
	_double = static_cast<double>(f);
}

void	cast::SrcDouble(std::string src)
{
	double	d = stod(src);

	_char = static_cast<char>(d);
	_int = static_cast<int>(d);
	_float = static_cast<float>(d);
	_double = static_cast<double>(d);
}


// char	cast::toChar(std::string src)
// {
// 	char c = src[0];

// 	_char = static_cast<char>(c);
// 	return (_char);






// }

// int		cast::toInt(std::string src)
// {
// 	int	i = stoi(src);

// 	_int = static_cast<int>(i);
// 	return (_int);
// }

// float	cast::toFloat(std::string src)
// {
// 	float	f = stof(src);

// 	_float = static_cast<float>(f);
// 	return (_float);
// }

// double	cast::toDouble(std::string src)
// {
// 	double	d = stod(src);

// 	_double = static_cast<double>(d);
// 	return (_double);
// }

char	cast::getChar() const
{
	return (_char);
}

int		cast::getInt() const
{
	return (_int);
}

float	cast::getFloat() const
{
	return (_float);
}

double	cast::getDouble() const
{
	return (_double);
}


cast::cast()
{
}

cast::~cast()
{
}
