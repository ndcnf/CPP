/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:28:06 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/12 11:31:30 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():
	Animal()
{
	_type = "dog";
	std::cout	<< "the " << _type << " is waking up and gently wiggling its tail."
				<< std::endl;
}

Dog::~Dog()
{
	std::cout	<< "the " << _type << " drops its favorite ball and is ready to bed."
				<< std::endl;
}

Dog::Dog(Dog const & src)
{
	*this = src;
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
