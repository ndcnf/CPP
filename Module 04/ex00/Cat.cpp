/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchennaf <nchennaf@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:19:43 by nchennaf          #+#    #+#             */
/*   Updated: 2023/01/09 13:52:40 by nchennaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():
	Animal()
{
	_type = "cat";
	std::cout	<< "the " << _type << " is waking up."
				<< std::endl;
}

Cat::~Cat()
{
	std::cout	<< "the " << _type << " is ready to bed."
				<< std::endl;
}

Cat::Cat(Cat const & src)
{
	*this = src;
}

Cat		&Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
		this->Animal::operator=(rhs);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout	<< "maow"
				<< std::endl;
}
