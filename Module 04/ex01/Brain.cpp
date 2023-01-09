/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:16:09 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 15:52:03 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		switch (i % 3)
		{
			case 0:
				std::cout << "I should buy a boat." << std::endl;
				break;
			case 1:
				std::cout << "Should I?" << std::endl;
				break;
			default:
				std::cout << "Definitely..." << std::endl;
				break;
		}
	}
}

Brain::Brain(Brain const & src)
{
	*this = src;
}

Brain::~Brain()
{
	std::cout	<< "brain in sleep mode."
				<< std::endl;
}

Brain	&Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}
