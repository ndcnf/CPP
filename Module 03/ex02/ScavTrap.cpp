/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:41 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 13:18:55 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
	ClapTrap("a Cyberman"),
	_guardStatus(false)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "* " << _name << " has been upgraded into a ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name),
	_guardStatus (false)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout	<< "* " << _name << " has been upgraded into a ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout	<< _name
				<< " has been DELETED."
				<< std::endl;
}


ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
		this->ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0 || this->_hitPoints <= 0)
	{
		std::cout	<< "> " << this->_name
					<< " tries to attack but hasn't any fuel or battery left."
					<< std::endl;
		return;
	}
	this->_energyPoints -= 1;
	this->_hitPoints -= this->_attackDamage;

	std::cout	<< "> ScavTrap " << this->_name << " attacks "
				<< target << ", causing "
				<< this->_attackDamage << " points of damage!"
				<< std::endl;
}

void	ScavTrap::guardGate()
{
	if (_guardStatus)
	{
		_guardStatus = false;
		std::cout	<< "> " << this->_name << " pushed the button: "
					<< "Gate Keeper mode OFF." << std::endl;
	}
	else
	{
		_guardStatus = true;
		std::cout	<< "> " << this->_name << " pushed the button: "
					<< "Gate Keeper mode ON." << std::endl;
	}
}

