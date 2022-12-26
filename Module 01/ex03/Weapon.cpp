/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:18:10 by nchennaf          #+#    #+#             */
/*   Updated: 2022/12/26 10:59:42 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	// std::cout	<< this->_type
	// 			<< " constructor called"
	// 			<< std::endl;
}

Weapon::~Weapon()
{
	// std::cout	<< this->_type
	// 			<< " destructor called"
	// 			<< std::endl;
}

std::string	const & Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
