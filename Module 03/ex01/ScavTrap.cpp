/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:41 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/05 16:18:39 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
	ClapTrap(),
	_guardStatus(false)
{
	_name = "a Cyberman";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name),
	_guardStatus (false)
{
	// _name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
		this->ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (_guardStatus)
	{
		_guardStatus = false;
		std::cout	<< "> " << this->_name << " pushed the button: " << std::endl;
		std::cout	<< "Gate Keeper mode OFF." << std::endl;
		std::cout	<< std::endl;
	}
	else
	{
		_guardStatus = true;
		std::cout	<< "> " << this->_name << " pushed the button: " << std::endl;
		std::cout	<< "Gate Keeper mode ON." << std::endl;
		std::cout	<< std::endl;
	}
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout	<< "> " << this->_name
					<< " tries to attack but hasn't any fuel or battery left."
					<< std::endl;
		std::cout	<< std::endl;

		return;
	}
	this->_energyPoints -= 1;
	this->_hitPoints -= this->_attackDamage;

	std::cout	<< "> ScavTrap " << this->_name << " attacks "
				<< target << ", causing "
				<< this->_attackDamage << " points of damage!"
				<< std::endl;
}
