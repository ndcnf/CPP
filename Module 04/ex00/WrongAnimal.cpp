/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:12:38 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 11:45:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("This animal is so wrong")
{
	std::cout	<< "An unexpected wrong animal opens an eye."
				<< std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "A random wrong animal is sleeping."
				<< std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
}

WrongAnimal		&WrongAnimal::operator=(WrongAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void		WrongAnimal::makeSound() const
{
	std::cout	<< "* generic sound for an unexpected animal *"
				<< std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
