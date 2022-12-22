/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:24:14 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/22 17:03:14 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie::Zombie()
{
	std::cout	<< "Zombie " << this->_name << " has risen"
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
