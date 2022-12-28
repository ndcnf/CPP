/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:37:59 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/28 12:43:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	karen;

	std::cout	<< "[DEBUG]: ";
	karen.complain("DEBUG");
	std::cout	<< "[INFO]: ";
	karen.complain("INFO");
	std::cout	<< "[WARNING]: ";
	karen.complain("WARNING");
	std::cout	<< "[ERROR]: ";
	karen.complain("ERROR");

	return (0);
}
