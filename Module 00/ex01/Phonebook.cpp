/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:38:48 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/21 10:33:20 by nchennaf         ###   ########.fr       */
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

// bool	Phonebook::searchContact(void)
// {
// 	if (this->getNbContact() == 0)
// 	{
// 		std::cout << "There is nobody in the phonebook." << std::endl;
// 		return (false);
// 	}

// 	this->printAllContacts();

// 	int prompt;
// 	std::cout << "Want to know more about whom? Enter their index number." << std::endl;
// 	std::cin >> prompt;

// 	if (prompt >= 0 && prompt < this->getNbContact()) {
// 		std::cout << "OUI" << std::endl;
// 		// this->retrieveContact(prompt);
// 		return (true);
// 	}
// 	std::cout	<< "Sorry, I don't know anyone by this index number. Please try again."
// 				<< std::endl;
// 	return (false);
// }

int	Phonebook::retrieveContact(int i)
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
	// std::cout	<< this->contact[i].getFirstName()
	// 			<< std::endl;
	// std::cout	<< this->contact[i].getNickname()
	// 			<< std::endl;
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
	return (0);

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
		return (true);
	}
	std::cout << "Sorry, I don't know anyone by this index number. Please try again." << std::endl;
	return (false);
}


// void	Phonebook::searchContact(void)
// {
// 	std::string		prompt;

// 	if (this->getNbContact() == 0)
// 	{
// 		std::cout	<< "There is nobody in the phonebook."
// 					<< std::endl;
// 		return;
// 	}
// 	this->printAllContacts();
// 	while (1)
// 	{
// 		std::cout	<< "Want to know more about whom? Enter their index number."
// 					<< std::endl;
// 		std::getline(std::cin, prompt);
// 		// std::cin	>> prompt;

// 		std::cout	<< "[" << prompt << "]"
// 					<< std::endl;


// 		if (stoi(prompt) > (this->getNbContact() - 1) || stoi(prompt) < 0)
// 		// if (std::cin.fail())
// 		{
// 			std::cout	<< "Sorry, I don't know anyone by this index number. Please try again."
// 						<< std::endl;
// 			// std::cin.clear();
// 			// std::cin.ignore();
// 			// prompt = std::n_pos;
// 			// std::cout	<< "Want to know more about whom? Enter their index number."
// 			// 			<< std::endl;
// 			continue;
// 		}

// 		// if (std::isdigit(prompt))
// 		// {
// 		// 	std::cout	<< "Not valid. Try again."
// 		// 				<< std::endl;
// 		// 	continue;
// 		// }

// 		if (stoi(prompt) >= 0 && stoi(prompt) < (this->getNbContact() - 1))
// 		{
// 			std::cout	<< "YEP"
// 						<< std::endl;
// 			break;
// 		}
// 		// std::cout	<< "Sorry, I don't know anyone by this index number. Please try again."
// 		// 			<< std::endl;
// 	}
// }

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
