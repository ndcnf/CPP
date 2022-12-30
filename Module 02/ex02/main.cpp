/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:28:27 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/30 15:29:24 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	// Fixed b(Fixed(5) + Fixed(3));
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a: " << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// if (b != a)
	// 	std::cout << b << " != " << a << std::endl;
	// else
	// 	std::cout << b << " == " << a << std::endl;

	// if (b == 8)
	// 	std::cout << b << " == " << 8 << std::endl;

	std::cout << "b: " << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
