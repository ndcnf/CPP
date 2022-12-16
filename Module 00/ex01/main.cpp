/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:00:52 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/16 10:46:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"Class.Phonebook.hpp"
// #include	"Class.Contact.hpp"

int	main(void)
{
	// Phonebook	book;
	// Contact		person;
	std::string	prompt;

	std::cout << "Welcome to this awesome phonebook !" << std::endl;
	std::cout << "Enter ADD, SEARCH or EXIT to proceed" << std::endl;
	std::cin >> prompt;
	std::cout << "You entered: " << prompt << std::endl;
	return (0);
}
