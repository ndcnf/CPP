/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/19 16:59:54 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout << "Constructor Phonebook called" << std::endl;
	this->_nbContact = 0;
	this->_index = 0;
	this->_entries = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor Phonebook called" << std::endl;
	return;
}

int	Phonebook::getNbContact(void) const
{
	return (this->_nbContact);
}

int	Phonebook::getIndex(void) const
{
	return (this->_index);
}

void	Phonebook::setIndex(void)
{
	if (this->getNbContact() < MAX_CONTACT)
		this->_index = this->getNbContact() - 1;
	else
		this->_index = this->_entries % MAX_CONTACT;
}

void	Phonebook::addContact(void)
{
	std::string		prompt;

	if (this->getNbContact() < MAX_CONTACT)
		this->_nbContact++;
	this->_entries++;
	this->setIndex();
	std::cout << Phonebook::getIndex() << std::endl;

	std::cout << "New contact to add:" << std::endl;

	std::cout << "First name: ";
	std::cin >> prompt;
	this->contact[this->_index].setFirstName(prompt);
	// this->contact[this->getNbContact() % MAX_CONTACT].setFirstName(prompt);

	std::cout << "Last name: ";
	std::cin >> prompt;
	this->contact[this->_index].setLastName(prompt);
	// this->contact[this->getNbContact() % MAX_CONTACT].setLastName(prompt);

	std::cout << "Nickname: ";
	std::cin >> prompt;
	this->contact[this->_index].setNickname(prompt);
	// this->contact[this->getNbContact() % MAX_CONTACT].setNickname(prompt);


	std::cout << "Telephone number: ";
	std::cin >> prompt;
	this->contact[this->_index].setTelephoneNum(prompt);
	// this->contact[this->getNbContact() % MAX_CONTACT].setTelephoneNum(prompt);


	std::cout << "Your darkest and utmost secret: ";
	std::cin >> prompt;
	this->contact[this->_index].setDarkestSecret(prompt);
	// this->contact[this->getNbContact() % MAX_CONTACT].setDarkestSecret(prompt);

	std::cout << "Contact number " << this->getNbContact() << " has been added" << std::endl;

	// std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getFirstName() << std::endl;
	// std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getLastName() << std::endl;
	// std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getNickname() << std::endl;
	// std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getTelephoneNum() << std::endl;
	// std::cout << this->contact[this->getNbContact() % MAX_CONTACT].getDarkestSecret() << std::endl;

// }
// else
// {
// 	if (this->i < MAX_CONTACT)
// 	{

// 		std::cout << "[" << this->getNbContact() << "]" << std::endl; // UNIQUEMENT POUR TESTS
// 	}
// 	else
// 	{
// 		this->i = 0;

// 	}
// }
}

void	Phonebook::searchContact(void)
{
	std::cout << ROW_SEPA << std::endl;
	std::cout << ROW_TITLE << std::endl;
	std::cout << ROW_SEPA << std::endl;

	for (int i = 0; i < this->getNbContact(); i++)
	{
		std::cout << "|         ";
		std::cout << this->getIndex() << WORD_SEPA;

		////////////////////////////////////////////////////////////
		// TO-DO HERE

		std::cout << this->wordToPrint(this->contact[this->_index].getFirstName()) << std::endl;
		std::cout << "[" << this->contact[this->_index].getFirstName().size() << "]" << std::endl;

		///////////////////////////////////////////////////////////




		// std::cout << this->contact[this->_index].getFirstName() << WORD_SEPA;
		std::cout << this->contact[this->_index].getLastName() <<  WORD_SEPA;
		std::cout << this->contact[this->_index].getNickname() <<  WORD_SEPA << std::endl;
		// std::cout << this->contact[this->_index].getTelephoneNum() << std::endl;
		// std::cout << this->contact[this->_index].getDarkestSecret() << std::endl;
	}
}

std::string	Phonebook::wordToPrint(std::string word)
{
	int	delta;
	// std::string	result;

	delta = word.length() - MAX_LEN;
	// std::cout << "DELTA : " << delta << std::endl;
	if (delta == 0)
		return (word);
	else if (delta < 0)
	{
		std::cout << "DELTA : " << delta << std::endl;

		// while (delta > 0)
		// {

		// 	delta--;
		// }
	}
	else
	{
		word.resize((unsigned)(MAX_LEN-1));
		word.append(".");
		// std::cout << word << std::endl;
	}
	return (word);
}
