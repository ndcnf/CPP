/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:28:27 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 14:19:45 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed 		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "----------- TESTS OBLIGATOIRES ------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------- TESTS COMPLEMENTAIRES ----------" << std::endl;
	Fixed 		c(Fixed(10));
	Fixed		d(Fixed(5));

	std::cout << c << " + " << d << " = " << (c+d) << std::endl;
	std::cout << d << " - " << c << " = " << (d-c) << std::endl;
	std::cout << c << " / " << d << " = " << (c/d) << std::endl;
	std::cout << c << " * " << d << " = " << (c*d) << std::endl;

	std::cout << std::endl;

	if (c != d)
		std::cout << c << " != " << d << std::endl;
	if (b == b)
		std::cout << c << " == " << c << std::endl;
	if (d < c)
		std::cout << c << " < " << d << std::endl;
	if (c > d)
		std::cout << c << " > " << d << std::endl;
	if (d <= c)
		std::cout << c << " <= " << d << std::endl;
	if (c >= d)
		std::cout << c << " >= " << d << std::endl;

	std::cout << std::endl;

	std::cout << "min(" << c << "," << d << ") : " << Fixed::min( c, d ) << std::endl;
	std::cout << "max(" << c << "," << d << ") : " << Fixed::max( c, d ) << std::endl;

	std::cout << std::endl;

	std::cout << "c   : " << c << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "c   : " << c << std::endl;
	std::cout << "c-- : " << c-- << std::endl;
	std::cout << "c   : " << c << std::endl;
	std::cout << "a   : " << a << std::endl;

	std::cout << "min(" << c << "," << d << ") : " << Fixed::min( c, d ) << std::endl;
	std::cout << "max(" << c << "," << d << ") : " << Fixed::max( c, d ) << std::endl;

	return 0;
}
