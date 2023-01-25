/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:43:21 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/25 16:48:18 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename T >
void	display(T const &toPrint)
{
	std::cout << toPrint << " ";
}

int	main()
{
	int			intArray[] = {2,3,1,4,6,7,3,8};
	std::string	stringArray[] = {"Mettre", "le", "char", "avant", "les boeufs"};
	float		floatArray[] = {1.2, 5.6, 9.2};

	iter(intArray, 8, display);
	std::cout << std::endl;

	iter(stringArray, 5, display);
	std::cout << std::endl;

	iter(floatArray, 3, display);
	std::cout << std::endl;

	return (0);
}

