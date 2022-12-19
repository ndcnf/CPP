/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 11:34:19 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Constructor Phonebook called" << std::endl;
	this->_nbContact = 0;
	// this->_nbContact++;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor Phonebook called" << std::endl;
	// this->_nbContact--;
	return;
}

int	Phonebook::getNbContact(void)
{
	return (this->_nbContact);
}

void	Phonebook::addContact(void)
{
	if (this->getNbContact() < 9)
	{
		std::cout << "moins de 9 ok" << std::endl;
		this->_nbContact++;
	}
	else
	{
		std::cout << "[" << this->getNbContact() << "]" << std::endl;
		std::cout << "9 ou plus" << std::endl;
	}

}
