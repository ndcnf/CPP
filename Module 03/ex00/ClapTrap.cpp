/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:26 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/04 15:13:33 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("Julien"),
	_hitPoints(HP),
	_energyPoints(EP),
	_attackDamage(AD)
{
	std::cout	<< "****** " << this->_name << " has entered the game!"
				<< " ******" << std::endl;
	std::cout	<< "HP: " << this->_hitPoints << std::endl
				<< "EP: " << this->_energyPoints << std::endl;

	std::cout	<< std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitPoints(HP),
	_energyPoints(EP),
	_attackDamage(AD)
{
	std::cout	<< "****** " << this->_name << " has entered the game!"
				<< " ******" << std::endl;
	std::cout	<< "HP: " << this->_hitPoints << std::endl
				<< "EP: " << this->_energyPoints << std::endl;

	std::cout	<< std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout	<< "###### " << this->_name << " has left the game!"
				<< " ######" << std::endl;

	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;

	std::cout	<< "HP: " << this->_hitPoints		<< std::endl
				<< "EP: " << this->_energyPoints	<< std::endl;

	std::cout	<< std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout	<< "> " << this->_name
					<< " tries to attack but hasn't any energy or health left."
					<< std::endl;
		std::cout	<< std::endl;

		return;
	}
	this->_energyPoints -= 1;

	std::cout	<< "> ClapTrap " << this->_name << " attacks "
				<< target << ", causing "
				<< this->_attackDamage << " points of damage!"
				<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0 || (this->_hitPoints - amount) <= 0)
	{
		std::cout	<< this->_name << " needs some rest. In peace." << std::endl;
		std::cout	<< std::endl;

		this->_hitPoints = 0;
		return;
	}
	this->_hitPoints -= amount;
	std::cout	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout	<< "> " << this->_name
					<< " tries to be repaired, but hasn't any energy or health left."
					<< std::endl;
		std::cout	<< std::endl;

		return;
	}
	this->_energyPoints += amount;
	std::cout	<< "> " << this->_name << " is being repaired." << std::endl
				<< this->_name << " loses 1 energy point and "
				<< "gains " << amount << " hit points"	<< std::endl;

	// std::cout	<< "HP: " << this->_hitPoints << std::endl
	// 			<< "EP: " << this->_energyPoints << std::endl;

	std::cout	<< std::endl;

}
