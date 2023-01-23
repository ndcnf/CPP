/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/23 16:28:49 by nchennaf         ###   ########.fr       */
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

	ca.detection(argv[1]);
	ca.selection(argv[1]);

	std::cout	<< "-- CONVERSIONS --" << std::endl;
	std::cout	<< "char:   " << ca.getChar()	<< std::endl;
	std::cout	<< "int:    " << ca.getInt()	<< std::endl;
	std::cout	<< "float:  " << ca.getFloat()	<< std::endl;
	std::cout	<< "double: " << ca.getDouble()	<< std::endl;

	return (0);
}
