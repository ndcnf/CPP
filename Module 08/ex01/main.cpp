/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:42 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/31 13:53:05 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	{
	std::cout << "-- Should return 2 for shortest and 14 for longest --" << std::endl;

		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout<< "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "-- Generates 12'000 random numbers in the vector. Results are random but valid. --" << std::endl;
		try
		{
			Span sp = Span(12000);
			sp.generateTab();

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout<< "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
	std::cout << "-- Should return 5 for shortest and longest --" << std::endl;

		try
		{
			Span sp = Span(2);
			sp.addNumber(6);
			sp.addNumber(11);

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout<< "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
	std::cout << "-- Should return an error: the size of the vector is not valid (too few) --" << std::endl;

		try
		{
			Span sp = Span(1);
			sp.addNumber(6);
			sp.addNumber(11);

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout<< "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
	std::cout << "-- Should return an error, there is a negtive number --" << std::endl;

		try
		{
			Span sp = Span(2);
			sp.addNumber(6);
			sp.addNumber(-11);

			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout<< "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}
