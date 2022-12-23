/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:31:56 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/23 17:00:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type): _name(name), weapon(type)
{
	// std::cout	<< this->_name
	// 			<< " constructor called"
	// 			<< std::endl;
}

HumanA::~HumanA()
{
	// std::cout	<< this->_name
	// 			<< " destructor called"
	// 			<< std::endl;
}

void	HumanA::attack()
{
	std::cout	<< this->_name
				<< " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}
