/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/21 13:11:06 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	<string>
#include	"Class.Phonebook.hpp"

Phonebook::Phonebook(void)
{
	std::cout	<< "Constructor Phonebook called"
				<< std::endl;
	this->_nbContact = 0;
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

void	Phonebook::addContact(void)
{
	std::string		prompt;

	if (this->getNbContact() < MAX_CONTACT)
		this->_nbContact++;

	std::cout	<< "New contact to add:"
				<< std::endl;

	std::cout	<< "First name: ";
	while (prompt.empty())
	{
		std::getline(std::cin, prompt);
		if (prompt.empty())
		{
			std::cout	<< "Please give me your first name."
						<< std::endl;
		}
	}
	this->contact[this->_entries % MAX_CONTACT].setFirstName(prompt);
	prompt.clear();

	std::cout	<< "Last name: ";
	while (prompt.empty())
	{
		std::getline(std::cin, prompt);
		if (prompt.empty())
		{
			std::cout	<< "Please give me your last name."
					<< std::endl;
		}
	}
	this->contact[this->_entries % MAX_CONTACT].setLastName(prompt);
	prompt.clear();

	std::cout	<< "Nickname: ";
	while (prompt.empty())
	{
		std::getline(std::cin, prompt);
		if (prompt.empty())
		{
			std::cout	<< "Please give me your nickname."
					<< std::endl;
		}
	}
	this->contact[this->_entries % MAX_CONTACT].setNickname(prompt);
	prompt.clear();

	std::cout	<< "Telephone number: ";
	while (prompt.empty())
	{
		std::getline(std::cin, prompt);
		if (prompt.empty())
		{
			std::cout	<< "Please give me your number."
					<< std::endl;
		}
	}
	this->contact[this->_entries % MAX_CONTACT].setTelephoneNum(prompt);
	prompt.clear();

	std::cout	<< "Your darkest and utmost secret: ";
	while (prompt.empty())
	{
		std::getline(std::cin, prompt);
		if (prompt.empty())
		{
			std::cout	<< "You can tell me. Go on. I won't tell anyone"
					<< std::endl;
		}
	}
	this->contact[this->_entries % MAX_CONTACT].setDarkestSecret(prompt);
	prompt.clear();

	this->_entries++;
}

void	Phonebook::retrieveContact(int i)
{
	std::cout	<< "Here is everything we know about them:"
				<< std::endl
				<< std::endl;
	std::cout	<< "FULL NAME"
				<< std::endl
				<< TITLE
				<< std::endl
				<< this->contact[i].getFirstName()
				<< " \""
				<< this->contact[i].getNickname()
				<< "\" "
				<< this->contact[i].getLastName()
				<< std::endl
				<< std::endl;
	std::cout	<< "TELEPHONE NUMBER"
				<< std::endl
				<< TITLE
				<< std::endl
				<< this->contact[i].getTelephoneNum()
				<< std::endl
				<< std::endl;
	std::cout	<< "DARKEST SECRET"
				<< std::endl
				<< TITLE
				<< std::endl
				<< this->contact[i].getDarkestSecret()
				<< std::endl
				<< std::endl;
}

bool Phonebook::searchContact(void)
{
	if (this->getNbContact() == 0)
	{
		std::cout	<< "There is nobody in the phonebook."
					<< std::endl;
		return (false);
	}

	this->printAllContacts();

    int prompt;
    std::cout	<< "Want to know more about whom? Enter their index number."
				<< std::endl;

	if (!(std::cin >> prompt))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout	<< "Sorry, you must enter a valid number. Please try again."
					<< std::endl;
		return (false);
	}

	if (prompt >= 0 && prompt < this->getNbContact())
	{
		this->retrieveContact(prompt);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (true);
	}
	std::cout	<< "Sorry, I don't know anyone by this index number. Please try again."
				<< std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (false);
}

void	Phonebook::printAllContacts(void)
{
	std::cout	<< this->getNbContact()
				<< " contact(s) in the phonebook"
				<< std::endl;
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
