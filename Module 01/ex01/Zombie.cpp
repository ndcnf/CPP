/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:45:15 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 12:04:46 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie()
{
	std::cout	<< "a new zombie has risen"
				<< std::endl;
}

Zombie::~Zombie()
{
	std::cout	<< this->getName()
				<< " has lost its head"
				<< std::endl;
}

std::string	Zombie::getName() const
{
	return (this->_name);
}

void	Zombie::setName(std::string name)
{
	if (!name.empty())
		this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout	<< this->getName()
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
