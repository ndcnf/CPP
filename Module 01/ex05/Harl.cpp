/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:46:01 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/28 12:41:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";

	this->_function[0] = &Harl::debug;
	this->_function[1] = &Harl::info;
	this->_function[2] = &Harl::warning;
	this->_function[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout	<< DEBUG
				<< std::endl;
}

void	Harl::info(void)
{
	std::cout	<< INFO
				<< std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< WARNING
				<< std::endl;
}

void	Harl::error(void)
{
	std::cout	<< ERROR
				<< std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < LVL_NB; i++)
	{
		if (level == _level[i])
		{
			(this->*_function[i])();
			return;
		}
	}
}
