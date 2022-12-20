/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/20 17:04:37 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout	<< "Constructor Phonebook called"
				<< std::endl;
	this->_nbContact = 0;
	this->_index = 0;
	this->_entries = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	std::cout	<< "Destructor Phonebook called"
				<< std::endl;
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
	std::cout << "Index [" << this->_index << "]" << std::endl;
}

void	Phonebook::addContact(void)
{
	std::string		prompt;

	if (this->getNbContact() < MAX_CONTACT)
		this->_nbContact++;

	std::cout	<< "New contact to add:"
				<< std::endl;

	std::cout	<< "First name: ";
	std::cin	>> prompt;
	this->contact[this->_entries % MAX_CONTACT].setFirstName(prompt);

	std::cout	<< "Last name: ";
	std::cin	>> prompt;
	this->contact[this->_entries % MAX_CONTACT].setLastName(prompt);

	std::cout	<< "Nickname: ";
	std::cin	>> prompt;
	this->contact[this->_entries % MAX_CONTACT].setNickname(prompt);

	std::cout	<< "Telephone number: ";
	std::cin	>> prompt;
	this->contact[this->_entries % MAX_CONTACT].setTelephoneNum(prompt);

	std::cout	<< "Your darkest and utmost secret: ";
	std::cin	>> prompt;
	this->contact[this->_entries % MAX_CONTACT].setDarkestSecret(prompt);

	this->setIndex();
	this->_entries++;
}

void	Phonebook::searchContact(void)
{
	// int		result;

	this->printAllContacts();


}

void	Phonebook::printAllContacts(void)
{
	std::cout	<< ROW_SEPA
				<< std::endl;
	std::cout	<< ROW_TITLE
				<< std::endl;
	std::cout	<< ROW_SEPA
				<< std::endl;

	for (int i = 0; i < this->getNbContact(); i++)
	{
		std::cout	<< WORD_SEPA
					<< std::setw(MAX_LEN)
					<< (i % MAX_CONTACT)
					<< WORD_SEPA;
		std::cout	<< std::setw(MAX_LEN)
					<< this->wordToPrint(this->contact[i % MAX_CONTACT].getFirstName())
					<< WORD_SEPA;
		std::cout	<< std::setw(MAX_LEN)
					<< this->wordToPrint(this->contact[i % MAX_CONTACT].getLastName())
					<< WORD_SEPA;
		std::cout	<< std::setw(MAX_LEN)
					<< this->wordToPrint(this->contact[i % MAX_CONTACT].getNickname())
					<< WORD_SEPA
					<< std::endl;
		std::cout	<< ROW_SEPA
					<< std::endl;
	}
}

std::string	Phonebook::wordToPrint(std::string word)
{
	if ((int)word.length() > MAX_LEN)
	{
		word.resize((unsigned)(MAX_LEN - 1));
		word.append(".");
	}
	return (word);
}
