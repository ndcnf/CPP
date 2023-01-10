/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:16:09 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/10 12:36:33 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = "I should buy a boat.";
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

std::string	Brain::getIdeas(int i) const
{
	return (this->_ideas[i]);
}
