/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:12:38 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:52:48 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal()
{
	std::cout	<< "An animal opens an eye."
				<< std::endl;
}

Animal::~Animal()
{
	std::cout	<< "An animal is sleeping."
				<< std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
}

Animal		&Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void		Animal::makeSound() const
{
	std::cout	<< "* generic sound for an animal *"
				<< std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}
