/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:02:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/24 10:44:17 by nchennaf         ###   ########.fr       */
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
	if (!ca.getValid())
		return (1);

	ca.selection(argv[1]);

	std::cout	<< "-- CONVERSIONS --" << std::endl;
	ca.printChar();
	ca.printInt();
	ca.printFloat();
	ca.printDouble();

	return (0);
}
