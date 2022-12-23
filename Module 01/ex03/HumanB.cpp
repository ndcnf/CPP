/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:06:41 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 16:21:43 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	std::cout	<< "HumanB constructor called"
				<< std::endl;
}

HumanB::~HumanB()
{
	std::cout	<< "HumanB destructor called"
				<< std::endl;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->weapon = &type;
}

void	HumanB::attack()
{
	std::cout	<< this->_name
				<< "attacks with their "
				<< this->weapon->getType()
				<< std::endl;
}

