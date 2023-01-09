/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:28:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:53:02 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():
	Animal()
{
	_type = "dog";
	std::cout	<< "the " << _type << " is waking up."
				<< std::endl;
}

Dog::~Dog()
{
	std::cout	<< "the " << _type << " is ready to bed."
				<< std::endl;
}

Dog		&Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
		this->Animal::operator=(rhs);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout	<< "woof"
				<< std::endl;
}
