/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:01:32 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 13:43:36 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

cast::cast(std::string conv):
		_char('0'),
		_int(0),
		_double(0.0),
		_float(0.0f),
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
	}
	return (*this);
}

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
				std::cout << "a float" << std::endl;
			}
			else
			{
				std::cout << "a double" << std::endl;
			}
		}
		else
		{
			std::cout	<< "an int" << std::endl;
		}

		pos = src.find("-");
		if (pos != std::string::npos)
			_hasSign = true;
	}
	else if (src.length() == 1)
	{
		std::cout << "a char" << std::endl;
	}
	else
	{
		std::cout << "Not a valid data here." << std::endl;
	}




	std::cout << std::endl;
	std::cout << "--- BOOL TESTS ---" << std::endl;
	std::cout << "point: " << _hasPoint << std::endl;
	std::cout << "sign:  " << _hasSign << std::endl;
	std::cout << "F:     " << _hasF << std::endl;
}

// char	cast::toChar(std::string src)
// {
// 	// _char = static_cast<char>(src);
// 	// return (_char);
// }

// int		cast::toInt(std::string src)
// {

// }

// float	cast::toFloat(std::string src)
// {

// }

// double	cast::toDouble(std::string src)
// {

// }


cast::cast()
{
}

cast::~cast()
{
}
