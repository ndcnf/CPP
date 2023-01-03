/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:26 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/03 16:25:13 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string s): _name(s)
{
	std::cout	<< "Constructor for "
				<< this->_name
				<< " called"
				<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{

}

ClapTrap::~ClapTrap()
{
	std::cout	<< "Destructor for "
				<< this->_name
				<< " called"
				<< std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0)
	{
		std::cout 	<< "ClapTrap "
					<< this->_name
					<< " attacks "
					<< "Someone"												//TODO name of the target TBD
					<< ", causing "
					<< this->_attackDamage
					<< " points of damage!"
					<< std::endl;
	}

}
