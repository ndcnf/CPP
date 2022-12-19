/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:01:44 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 11:27:21 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Constructor Contact called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Destructor Contact called" << std::endl;
	return;
}

std::string	Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string	Contact::getLasttName(void) const
{
	return this->_lastName;
}

std::string	Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string	Contact::getTelephoneNum(void) const
{
	return this->_telephoneNum;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

void	Contact::setFirstName(std::string s)
{
	if (!s.empty())
	{
		this->_firstName = s;
		return;
	}
}

void	Contact::setLasttName(std::string s)
{
	if (!s.empty())
	{
		this->_lastName = s;
		return;
	}
}

void	Contact::setNickname(std::string s)
{
	if (!s.empty())
	{
		this->_nickname = s;
		return;
	}
}

void	Contact::setTelephoneNum(std::string s)
{
	if (!s.empty())
	{
		this->_telephoneNum = s;
		return;
	}
}
void	Contact::setDarkestSecret(std::string s)
{
	if (!s.empty())
	{
		this->_darkestSecret = s;
		return;
	}
}
