/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:24:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:52:45 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie()
{
	std::cout	<< "Something has risen from the ground"
				<< std::endl;
}

Zombie::~Zombie()
{
	std::cout	<< "Zombie " << this->_name << " has fallen"
				<< std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
	return;
}

void	Zombie::announce()
{
	std::cout	<< this->_name
				<< ": BraiiiiiiinnnzzzZ..."
				<< std::endl;
}
