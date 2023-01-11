/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:57:31 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/11 13:32:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():
	_name("Julien")
{
	for (int i = 0; i < SLOTS; i++)
		_inventory[i].empty();
}

Character::Character(std::string name):
	_name(name)
{
	for (int i = 0; i < SLOTS; i++)
		_inventory[i].empty();
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{
	std::cout	<< _name << " is dead."
				<< std::endl;
}

Character	&Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return (*this);
}


std::string const &	Character::getName() const
{
	return (this->_name);
}

// void	Character::equip(AMateria* m)
// {

// }

// void	Character::unequip(int idx)
// {

// }

// void	Character::use(int idx, ICharacter& target)
// {

// }

