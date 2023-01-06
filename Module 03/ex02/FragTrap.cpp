/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:41:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/06 13:40:33 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():
	ClapTrap("a random bro"),
	_highFiveAcknowledged(false)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "* " << _name << " wants to high five every bro in the room." << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name),
	_highFiveAcknowledged(false)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout	<< "* " << _name << " wants to high five every bro in the room." << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout	<< _name
				<< " was TOO chill."
				<< std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
		this->ClapTrap::operator=(rhs);
	return (*this);
}

bool	FragTrap::getHighFiveAcknoledged()
{
	return (this->_highFiveAcknowledged);
}

void	FragTrap::highFivesGuys(void)
{
	std::string	coolBro;

	while (!_highFiveAcknowledged)
	{
		std::cout		<< "High five, bro!: ";
		std::getline(std::cin, coolBro);

		if (coolBro.empty() || coolBro == "\n")
		{
			std::cout	<< "Bro. Don't left me hanging. High five me, dude..." << std::endl;
			continue;
		}

		for (int i = 0; i < coolBro.length(); i++)
			coolBro[i] = tolower(coolBro[i]);

		if (coolBro == "high five")
		{
			std::cout	<< "YEAH, DUDE! You're chill. We should be best bro now." << std::endl;
			_highFiveAcknowledged = true;
		}
		else if (coolBro == "no")
		{
			std::cout << "Rude, dude." << std::endl;
			break;
		}
		else
			std::cout << "C'mon, bro. Just need a \"high five\"." << std::endl;
	}
}
