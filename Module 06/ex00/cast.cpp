/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:32 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 15:37:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

cast::cast(std::string conv):
		_char('0'),
		_int(0),
		_double(0.0),
		_float(0.0f),
		_isChar(false),
		_isInt(false),
		_isFloat(false),
		_isDouble(false),
		_hasPoint(false),
		_hasSign(false),
		_hasF(false)
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
	}
	return (*this);
}

// void	cast::exceptions(std::string src)
// {
// 	switch (src)
// 	{
// 	case "nanf":
// 		/* code */
// 		break;

// 	default:
// 		break;
// 	}
// }

void	cast::detection(std::string src)
{
	int				i = 0;
	std::size_t		pos;

	pos = src.find_first_not_of("0123456789");
	if (pos)
	{
		pos = src.find(".");
		if (pos != std::string::npos)
		{
			_hasPoint = true;
			pos = src.find("f");
			if (pos != std::string::npos)
			{
				_hasF = true;
				_isFloat = true;
				// this->toFloat(src);
			}
			else
			{
				_isDouble = true;
				// this->toDouble(src);
			}
		}
		else
		{
			_isInt = true;
			// this->toInt(src);
		}

		pos = src.find("-");
		if (pos != std::string::npos)
			_hasSign = true;
	}
	else if (src.length() == 1)
	{
		_isChar = true;
		// this->toChar(src);
	}
	// else if (src == "nan" || src == "inff" || src == "nanf" || src == "inf")
		// exceptions(src);
	else
	{
		std::cout << "Not a valid data here." << std::endl;
	}


	std::cout << std::endl;
	std::cout << "--- BOOL TESTS ---" << std::endl;
	std::cout << "point:  " << _hasPoint << std::endl;
	std::cout << "sign:   " << _hasSign << std::endl;
	std::cout << "f:      " << _hasF << std::endl;
	std::cout << "isChar: " << _isChar <<std::endl;
	std::cout << "isInt:  " << _isInt <<std::endl;
	std::cout << "ifFlt:  " << _isFloat <<std::endl;
	std::cout << "isDble: " << _isDouble <<std::endl;
}

char	cast::toChar(std::string src)
{
	char c = src[0];

	_char = static_cast<char>(c);
	return (_char);
}

int		cast::toInt(std::string src)
{
	int	i = stoi(src);

	_int = static_cast<int>(i);
	return (_int);
}

float	cast::toFloat(std::string src)
{
	float	f = stof(src);

	_float = static_cast<float>(f);
	return (_float);
}

double	cast::toDouble(std::string src)
{
	double	d = stod(src);

	_double = static_cast<double>(d);
	return (_double);
}

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
