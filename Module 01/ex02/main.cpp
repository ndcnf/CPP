/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 12:35:55 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 12:54:04 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	////////////////////////////
	// Informations to print
	////////////////////////////
	std::cout	<< "Adresse de la string :			"
				<< "["
				<< &brain
				<< "]"
				<< std::endl;

	std::cout	<< "Adresse stockee dans stringPTR :	"
				<< "["
				<< stringPTR
				<< "]"
				<< std::endl;

	std::cout	<< "Adresse stockee dans stringREF :	"
				<< "["
				<< &stringREF
				<< "]"
				<< std::endl;

	std::cout	<< "Valeur de la string :			"
				<< "["
				<< brain
				<< "]"
				<< std::endl;

	std::cout	<< "Valeur pointee par stringPTR :		"
				<< "["
				<< *stringPTR
				<< "]"
				<< std::endl;

	std::cout	<< "Valeur pointee par stringREF :		"
				<< "["
				<< stringREF
				<< "]"
				<< std::endl;
}
