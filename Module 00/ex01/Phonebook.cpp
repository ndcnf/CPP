/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 12:06:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Constructor Phonebook called" << std::endl;
	this->_nbContact = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor Phonebook called" << std::endl;
	return;
}

int	Phonebook::getNbContact(void)
{
	return (this->_nbContact);
}

void	Phonebook::addContact(void)
{
	std::string		prompt;
	if (this->getNbContact() < MAX_CONTACT)
	{
		std::cout << "New contact to add:" << std::endl;

		std::cout << "First name: ";
		std::cin >> prompt;
		this->contact[this->getNbContact() % MAX_CONTACT].setFirstName(prompt);


		std::cout << "Last name: ";
		std::cin >> prompt;
		this->contact[this->getNbContact() % MAX_CONTACT].setLastName(prompt);

		std::cout << "Nickname: ";
		std::cin >> prompt;
		this->contact[this->getNbContact() % MAX_CONTACT].setNickname(prompt);


		std::cout << "Telephone number: ";
		std::cin >> prompt;
		this->contact[this->getNbContact() % MAX_CONTACT].setTelephoneNum(prompt);


		std::cout << "Your darkest and utmost secret: ";
		std::cin >> prompt;
		this->contact[this->getNbContact() % MAX_CONTACT].setDarkestSecret(prompt);

		std::cout << "Contact number " << this->getNbContact() << " has been added" << std::endl;
		std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getFirstName() << std::endl;
		std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getLastName() << std::endl;
		std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getNickname() << std::endl;
		std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getTelephoneNum() << std::endl;
		std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getDarkestSecret() << std::endl;

		this->_nbContact++;
	}
	else
	{
		std::cout << "[" << this->getNbContact() << "]" << std::endl; // UNIQUEMENT POUR TESTS
	}

}
