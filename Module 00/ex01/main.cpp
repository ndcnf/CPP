/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:00:52 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/20 15:34:45 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"
#include	"Class.Contact.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	prompt;

	std::cout	<< TITLE
				<< std::endl;
	std::cout	<< "*    Welcome to this awesome phonebook !    *"
				<< std::endl;
	std::cout	<< TITLE
				<< std::endl;

	while (1)
	{
		std::cout	<< "Enter ADD, SEARCH or EXIT to proceed..."
					<< std::endl;
		std::cin	>> prompt;
		for (int i = 0; i < (int)prompt.length(); i++)
			prompt[i] = (char)toupper(prompt[i]);
		std::cout	<< "You entered: [" << prompt << "]"
					<< std::endl;

		if (prompt == "EXIT")
			break;

		if (prompt != "ADD" && prompt != "SEARCH")
		{
			std::cout	<< "[" << prompt << "] is an invalid command. Please try again."
						<< std::endl;
			continue;
		}

		// Everything is valid down here --------------------------------------
		if (prompt == "ADD")
		{
			phonebook.addContact();
		}

		if (prompt == "SEARCH")
		{
			phonebook.searchContact();
		}
		std::cout	<< phonebook.getNbContact()
					<< " contact(s) in the phonebook"
					<< std::endl;
	}
	return (0);
}

/* TO-DO
	[]	Le meme index est appele dans le tableau SEARCH
	[]	Verifier que l'entree d'avant n'est pas ecrasee
	[x]	Comprendre 'resize' car ne fonctionne pas actuellement OU ne semble pas le faire
	[]	"Contact number x has been added" a corriger avec un -1 OU ne pas l'afficher en prod
	[x]	unisgned pour le resize ?
	[x]	ne passe pas dans le else pour le resize
	[x ]	regler le -27 pour delta
*/
