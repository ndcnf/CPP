/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:15:26 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/04 12:47:22 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string s): _name(s)
{
	this->_hitPoints = HP;
	this->_energyPoints = EP;
	this->_attackDamage = AD;
	std::cout	<< "****** "
				<< this->_name
				<< " has entered the game!"
				<< " ******"
				<< std::endl;
	std::cout	<< "HP: "
				<< this->_hitPoints
				<< std::endl
				<< "EP: "
				<< this->_energyPoints
				<< std::endl;

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
	std::cout	<< "###### "
				<< this->_name
				<< " has left the game!"
				<< " ######"
				<< std::endl;
	std::cout	<< "HP: " << this->_hitPoints		<< std::endl
				<< "EP: " << this->_energyPoints	<< std::endl;

	std::cout	<< std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	//NOTE To be deleted, ONLY FOR TESTS
	std::cout	<< "energy: " << this->_energyPoints
				<< " | hit points:" << this->_hitPoints
				<< std::endl;

	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std::cout 	<< "ClapTrap "
					<< this->_name
					<< " attacks "
					<< target
					<< ", causing "
					<< this->_attackDamage
					<< " points of damage!"
					<< std::endl;

		this->_energyPoints -= 1;
	}
	else if (this->_energyPoints)
	{
		std::cout	<< this->_name
					<< " hasn't enough hit points left."
					<< std::endl;
	}
	else
	{
		std::cout	<< this->_name
					<< " hasn't enough energy left."
					<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout	<< this->_name		<< std::endl
				<< "HP -" << amount	<< std::endl;

	std::cout	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0 && this->_hitPoints <= 0)
	{
		std::cout	<< this->_name
					<< " hasn't any energy or health left, therefore can't be repaired"
					<< std::endl;
		return;
	}
	this->_energyPoints -= amount;
	std::cout	<< this->_name		<< std::endl
				<< "-1  EP"			<< std::endl
				<< "+" << amount << " HP"	<< std::endl
				<< "------"<< std::endl;

	std::cout	<< "HP: "
				<< this->_hitPoints
				<< std::endl
				<< "EP: "
				<< this->_energyPoints
				<< std::endl;

	std::cout	<< std::endl;

}
