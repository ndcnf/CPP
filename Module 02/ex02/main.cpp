/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:28:27 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 13:09:00 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "--------- TESTS OBLIGATOIRES ---------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "--------- TESTS COMPLEMENTAIRES ---------" << std::endl;
	Fixed 		c(10);
	std::cout << "c:   " << c << std::endl;
	std::cout << "--c: " << --c << std::endl;
	std::cout << "c:   " << c << std::endl;
	std::cout << "c--: " << c-- << std::endl;
	std::cout << "c:   " << c << std::endl;

	if (b != a)
		std::cout << b << " != " << a << std::endl;
	else
		std::cout << b << " == " << a << std::endl;

	if (b == b)
		std::cout << b << " == " << b << std::endl;

	std::cout << Fixed::min(a, b) << std::endl;

	return 0;
}
