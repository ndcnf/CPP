/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 12:50:31 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please enter one parameter." << std::endl;
		return(1);
	}

	cast	ca(argv[1]);

	std::cout	<< "-- CONVERSIONS --" << std::endl;
	ca.detection(argv[1]);

	// std::cout	<< "char:   " << static_cast<char>(argv[1])		<< std::endl;
	// std::cout	<< "int:    " << static_cast<int>(argv[1])		<< std::endl;
	// std::cout	<< "float:  " << static_cast<float>(argv[1])	<< std::endl;
	// std::cout	<< "double: " << static_cast<double>(argv[1])	<< std::endl;

	return (0);
}
