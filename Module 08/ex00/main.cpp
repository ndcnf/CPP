/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:35:56 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/27 14:10:10 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main()
{
	std::cout << "--- [VECTOR] ---" << std::endl;
	std::vector<int>	elemVect;
	elemVect.push_back(2);
	elemVect.push_back(4);
	elemVect.push_back(8);
	elemVect.push_back(12);
	elemVect.push_back(28);
	elemVect.push_back(234);

	try
	{
		std::cout << "3 is not in the vector ---> ";
		easyfind(elemVect, 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "4 is in the vector ---> ";
		easyfind(elemVect, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- [LIST] ---" << std::endl;

	std::list<int>	elemLst;
	elemLst.push_back(2);
	elemLst.push_back(4);
	elemLst.push_back(8);
	elemLst.push_back(12);
	elemLst.push_back(28);
	elemLst.push_back(234);

	try
	{
		std::cout << "3 is not in the list ---> ";
		easyfind(elemLst, 3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "4 is in the list ---> ";
		easyfind(elemLst, 4);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
