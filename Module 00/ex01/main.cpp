/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:00:52 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 15:42:16 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"
#include	"Class.Contact.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	prompt;

	std::cout << "Welcome to this awesome phonebook !" << std::endl;
	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT to proceed" << std::endl;
		std::cin >> prompt;
		for (int i = 0; i < (int)prompt.length(); i++)
			prompt[i] = (char)toupper(prompt[i]);
		std::cout << "You entered: [" << prompt << "]" << std::endl;
		if (prompt == "EXIT")
			break;
		if (prompt != "ADD" && prompt != "SEARCH")
		{
			std::cout << "[" << prompt << "] is an invalid command. Please try again." << std::endl;
			continue;
		}
		std::cout << "It is valid." << std::endl;
	}
	return (0);
}
