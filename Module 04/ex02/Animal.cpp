/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:12:38 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 13:35:34 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
{
	std::cout	<< "An animal opens an eye."
				<< std::endl;
}

AAnimal::~AAnimal()
{
	std::cout	<< "An animal is sleeping."
				<< std::endl;
}

AAnimal::AAnimal(AAnimal const & src)
{
	*this = src;
}

AAnimal		&AAnimal::operator=(AAnimal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void		AAnimal::makeSound() const
{
	std::cout	<< "* generic sound for an animal *"
				<< std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}
